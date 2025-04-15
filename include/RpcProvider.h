#pragma once

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
};

} // namespace myrpc