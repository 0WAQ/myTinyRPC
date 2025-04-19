#include "RpcApplication.h"
#include "RpcProvider.h"
#include "RpcConfig.h"

namespace myrpc
{

void RpcProvider::notify_service(gp::Service *service)
{

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