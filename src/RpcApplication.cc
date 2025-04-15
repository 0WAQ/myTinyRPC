#include <unistd.h>

#include <Logger.h>

#include "RpcApplication.h"

namespace myrpc
{

RpcApplication& RpcApplication::instance()
{
    static RpcApplication singleton;
    return singleton;
}

void RpcApplication::init(int argc, char* argv[])
{
    if (argc < 2) {
        LOG_ERROR("format: command -i <config file>.\n");
    }

    int c = 0;

    std::string config_file;
    while ((c = getopt(argc, argv, "i:"))) {
        switch (c)
        {
        case 'i':
            config_file = optarg;
            break;
        case '?':
            LOG_ERROR("Invalid args! format: command -i <config_file>.\n");
        case ':':
            LOG_ERROR("format: command -i <config_file>.\n");
        default:
            break;
        }
    }

    // 加载配置文件
    
}

} // namespace myrpc