#include "RpcChannel.h"
#include "RpcApplication.h"
#include "RpcHeader.pb.h"

#include <InetAddress.h>
#include <Socket.h>
#include <Logger.h>

#include <sys/socket.h>
#include <sys/types.h>

namespace myrpc
{

void RpcChannel::CallMethod(const gp::MethodDescriptor *method,
                    gp::RpcController *controller,
                    const gp::Message *request,
                    gp::Message *response,
                    gp::Closure *done)
{
    /**
     * header_size + service_name
     * args_size + args
     */

    const gp::ServiceDescriptor *service_desc = method->service();

    std::string service_name = service_desc->name();
    std::string method_name = method->name();

    uint32_t args_size = 0;
    std::string args_str;
    if(!request->SerializeToString(&args_str)) {
        LOG_ERROR("serialize request error.\n");
    }
    
    args_size = args_str.size();
        

    RpcHeader header;
    header.set_service_name(service_name);
    header.set_method_name(method_name);
    header.set_args_size(args_size);

    std::string header_str;
    uint32_t header_size = 0;
    if(!header.SerializeToString(&header_str)) {
        LOG_ERROR("serialize header error.\n");
    }

    header_size = header_str.size();

    // 填充请求字节流
    std::string send_buf{ };
    send_buf.append(std::string{(char*)&header_size, 4});
    send_buf.append(header_str);
    send_buf.append(args_str);

    RpcConfig config = RpcApplication::instance().config();
    std::string ipv4 = config.get("server_ip");
    uint16_t port = std::atoi(config.get("server_port").c_str());

    // 调用远程方法
    mymuduo::Socket clnt_sock{ ::socket(AF_INET, SOCK_STREAM, 0) };
    mymuduo::InetAddress server_addr{ ipv4, port };

    // TODO: 暂且直连
    if(::connect(clnt_sock.get_fd(), server_addr.get_addr(), sizeof(sockaddr_in)) == -1) {
        LOG_ERROR("connect error.\n");
    }

    // 发送 rpc 请求
    if(::send(clnt_sock.get_fd(), send_buf.c_str(), send_buf.size(), 0) == -1) {
        LOG_ERROR("send error, errno: %d.\n", errno);
    }

    // 获取 rpc 响应结果
    char recv_buf[1024]{ };
    uint32_t recv_size = 0;
    if((recv_size = ::recv(clnt_sock.get_fd(), recv_buf, 1024, 0)) == -1) {
        LOG_ERROR("recv error, errno: %d.\n", errno);
    }

    // 反序列化response
    if(!response->ParseFromArray(recv_buf, recv_size)) {
        LOG_ERROR("parse error.\n");
    }
}

} // myrpc