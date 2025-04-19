#pragma once

#include <noncopyable.h>

#include "RpcConfig.h"

namespace myrpc
{

/**
 * @brief Rpc框架基础类
 */
class RpcApplication : mymuduo::noncopyable
{
public:

    /**
     * @brief 获取单例
     */
    static RpcApplication& instance();
    
    /**
     * @brief 初始化框架
     */
    static void init(int argc, char* argv[]);

    /**
     * @brief 获取配置信息
     */
    static RpcConfig& config();

private:

    static RpcConfig _M_config;

};

} // namespace myrpc;