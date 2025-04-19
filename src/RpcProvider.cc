#include "RpcApplication.h"
#include "RpcProvider.h"
#include "RpcConfig.h"

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

}

void RpcProvider::on_message(const mymuduo::TcpConnectionPtr& conn,
                mymuduo::Buffer* buffer,
                mymuduo::TimeStamp timestamp)
{

}

} // namespace myrpc