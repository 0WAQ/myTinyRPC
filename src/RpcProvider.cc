#include "RpcApplication.h"
#include "RpcProvider.h"
#include "RpcConfig.h"
#include "RpcHeader.pb.h"

#include <Logger.h>

namespace myrpc
{

namespace gp = google::protobuf;

void RpcProvider::notify_service(gp::Service *service)
{
    // 服务信息
    ServiceInfo info;
    info.service = service;

    // 获取服务对象的描述
    const gp::ServiceDescriptor *service_desc = service->GetDescriptor();
    
    // 服务的名称与方法数
    std::string name = service_desc->name();
    int method_cnt = service_desc->method_count();

    // 遍历获取所有方法描述
    for(int i = 0; i < method_cnt; ++i) {
        const gp::MethodDescriptor *method_desc = service_desc->method(i);
        std::string method_name = method_desc->name();

        info.method_map.insert({name, method_desc});
    }

    _M_service_map.insert({name, info});
}

void RpcProvider::run()
{
    RpcConfig config = RpcApplication::instance().config();

    std::string ip = config.get("server_ip");
    uint16_t port = (uint16_t)atoi(config.get("server_port").c_str());
    
    mymuduo::InetAddress addr{ip, port};
    mymuduo::TcpServer server{&_M_loop, addr, "RpcProvider"};

    using namespace std::placeholders;
    server.set_connection_callback(std::bind(&RpcProvider::on_connection, this, _1));
    server.set_message_callback(std::bind(&RpcProvider::on_message, this, _1, _2, _3));
    
    server.set_thread_num(4);

    server.start();
    _M_loop.loop();

}

void RpcProvider::on_connection(const mymuduo::TcpConnectionPtr& conn)
{
    // 若连接已建立, 则此次为连接断开, 关闭连接
    if(!conn->connected()) {
        conn->shutdown();
    }
}

void RpcProvider::on_message(const mymuduo::TcpConnectionPtr& conn,
                mymuduo::Buffer* buffer,
                mymuduo::TimeStamp timestamp)
{
    // 1. rpc服务收到的字节流, 应反序列化为protobuf对象
    std::string buf = buffer->retrieve_all_as_string();

    // 2. 读取长度
    uint32_t header_size = 0;
    buf.copy((char*)&header_size, 4, 0);

    // 3. 读取原始字符流
    std::string header_str = buf.substr(4, header_size);
    
    // 4. 反序列化
    myrpc::RpcHeader header;
    if(!header.ParseFromString(header_str)) {
        // 反序列化失败
        LOG_ERROR("header_str parse error, str is %s", header_str.c_str());
    }
    
    std::string service_name{ header.service_name() };
    std::string method_name{ header.method_name() };

    uint32_t args_size{ header.args_size() };
    std::string args_str = buf.substr(4 + header_size, args_size);

    // 获取service和method对象
    auto it = _M_service_map.find(service_name);
    if(it == _M_service_map.end()) {
        // 无效的服务名
        LOG_WARN("Invalid service name: %s\n", service_name.c_str());
        return;
    }

    auto mit = it->second.method_map.find(method_name);
    if(mit == it->second.method_map.end()) {
        // 无效的方法名
        LOG_WARN("Invalid method name: %s\n", method_name.c_str());
        return;
    }
    
    gp::Service *service = it->second.service;
    const gp::MethodDescriptor *method = mit->second;

    // 5. 获取Request和Response对象
    gp::Message *request = service->GetRequestPrototype(method).New();
    gp::Message *response = service->GetResponsePrototype(method).New();
    
    // 6. 解析请求args_str的字节流
    if(!request->ParseFromString(args_str)) {
        // 解析参数失败
        LOG_WARN("request parse error, invalid args: %s\n", args_str.c_str());
        return;
    }

    // 7. 绑定Closure回调
    using namespace std::placeholders;
    gp::Closure *done = gp::NewCallback<RpcProvider,
                                        const mymuduo::TcpConnectionPtr&,
                                        gp::Message*> (
                                                    this,
                                                    &RpcProvider::send_rpc_response,
                                                    conn,
                                                    response);

    // 8. 调用方法
    service->CallMethod(method, nullptr, request, response, done); 
}

void RpcProvider::send_rpc_response(const mymuduo::TcpConnectionPtr& conn,
                gp::Message* response)
{
    // 序列化响应
    std::string buf;
    if(!response->SerializeToString(&buf)) {
        // 序列化失败
        LOG_WARN("Serialize response to str error.\n");
        return;
    }

    // 发送响应
    conn->send(buf);
    conn->shutdown();   // 服务方主动断开连接
}

} // namespace myrpc