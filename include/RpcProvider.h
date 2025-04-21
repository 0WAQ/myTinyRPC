#pragma once

#include <memory>
#include <functional>
#include <unordered_map>

#include <TcpServer.h>
#include <TcpConnection.h>
#include <EventLoop.h>
#include <InetAddress.h>
#include <Buffer.h>
#include <TimeStamp.h>

#include <google/protobuf/service.h>
#include <google/protobuf/descriptor.h>

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

    /**
     * @brief 连接到达
     */
    void on_connection(const mymuduo::TcpConnectionPtr& conn);

    /**
     * @brief rpc请求
     */
    void on_message(const mymuduo::TcpConnectionPtr& conn,
                    mymuduo::Buffer* buffer,
                    mymuduo::TimeStamp timestamp);

    /**
     * @brief Closure回调操作, 用于序列化rpc的响应和网络发送
     */
    void send_rpc_response(const mymuduo::TcpConnectionPtr& conn,
                    gp::Message*);

private:

    mymuduo::EventLoop _M_loop;

    // 服务信息
    struct ServiceInfo {
        // 服务的对象地址
        google::protobuf::Service *service;
        
        // 保存服务的所有方法
        std::unordered_map<std::string,
                            const google::protobuf::MethodDescriptor*>
            method_map;
    };

    // 注册成功的服务信息表
    std::unordered_map<std::string, ServiceInfo> _M_service_map;
};

} // namespace myrpc