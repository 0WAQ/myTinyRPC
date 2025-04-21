#include <iostream>

#include "RpcApplication.h"
#include "RpcChannel.h"

#include "../user.pb.h"

using namespace myrpc;

int main(int argc, char* argv[])
{
    RpcApplication::init(argc, argv);

    example::UserServiceRpc_Stub stub{ new RpcChannel{ } };

    example::LoginRequest req;
    example::LoginResponse res;

    req.set_name("0WAQ");
    req.set_pwd("0WAQ123");

    // 发起rpc调用, 服务调用者会阻塞在这里, 直到远程服务返回
    stub.login(nullptr, &req, &res, nullptr);

    // 读取响应的结果 
    if(!res.success()) {
        printf("rpc login response error: %s\n", res.result().errmsg().c_str());
        return 0;
    }

    printf("rpc login response success.\n");

    return 0;
}