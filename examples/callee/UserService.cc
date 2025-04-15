#include <iostream>
#include <string>

#include <Logger.h>

#include "RpcApplication.h"
#include "RpcProvider.h"

#include "../user.pb.h"

using namespace mymuduo;
using namespace example;
using namespace myrpc;

namespace gp = ::google::protobuf;

/**
 * 提供进程间的通信方法
 */
class UserService : public UserServiceRpc
{
public:

    /**
     * @brief login的业务逻辑
     */
    bool login(std::string name, std::string pwd) {
        printf("doing local service: login\nname: %s, pwd: %s", name.c_str(), pwd.c_str());
        return true;
    }

    /**
     * @brief callee
     * 
     * 1. caller ==> UserServiceRpc_Stub::login(LoginRequest) ==> mymuduo ==> callee
     * 2. callee ==> UserServiceRpc_Stub::login(LoginRequest) ==> UserService::login
     */
    void login(gp::RpcController* controller,
                        const LoginRequest* req,
                        LoginResponse* res,
                        gp::Closure* done)
    {
        // login的业务逻辑
        std::string name = req->name(), pwd = req->pwd();

        // 执行业务逻辑
        bool result = login(name, pwd);
    
        // 将响应写入response
        ResultCode *rc = res->mutable_result();
        rc->set_errcode(0);
        rc->set_errmsg("");
        res->set_success(result);
    
        // 执行回调, 执行响应对象的序列化和发送, 由框架提供
        done->Run();
    }
};

int main(int argc, char *argv[])
{
    Logger* log = Logger::get_instance("../log", "examples");
    log->init(Logger::DEBUG);

    // 初始化框架
    RpcApplication::init(argc, argv);

    // 发布服务
    RpcProvider provider;
    provider.notify_service(new UserService());
    // provider.notify_service(new xxxService());


    // 启动发布的服务
    provider.run();

    return 0;
}
