#include <iostream>

#include "RpcApplication.h"
#include "RpcChannel.h"

#include "../user.pb.h"

using namespace myrpc;

int main(int argc, char* argv[])
{
    RpcApplication::init(argc, argv);

    example::UserServiceRpc_Stub stub{ new RpcChannel{ } };

    return 0;
}