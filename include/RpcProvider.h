#pragma once

#include <memory>

#include <TcpServer.h>
#include <TcpConnection.h>
#include <EventLoop.h>
#include <InetAddress.h>
#include <Buffer.h>
#include <TimeStamp.h>

#include "google/protobuf/service.h"

namespace myrpc
{

namespace gp = ::google::protobuf;

/**
 * @brief 服务提供对象
 */
class RpcProvider
{
public:

    /**
     * @brief 发布服务
     */
    void notify_service(gp::Service *service);

    /**
     * @brief 启动rpc服务节点
     */
    void run();

private:

    void on_connection(const mymuduo::TcpConnectionPtr& conn);

    void on_message(const mymuduo::TcpConnectionPtr& conn,
                    mymuduo::Buffer* buffer,
                    mymuduo::TimeStamp timestamp);

private:

    mymuduo::EventLoop _M_loop;

};

} // namespace myrpc