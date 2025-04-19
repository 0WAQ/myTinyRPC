#include <vector>
#include <string>

#include <Logger.h>

#include "RpcConfig.h"

namespace myrpc
{

void RpcConfig::load(const std::string& config_file)
{
    FILE *file = fopen(config_file.c_str(), "r");
    if(file == nullptr) {
        LOG_ERROR("config file does't exist!\n");
    }

    while(!feof(file)) {
        int len = 128;
        std::string buf;
        buf.resize(len);

        fgets(buf.data(), len, file);

        std::string key;
        std::string val;
        
        int i; char c;
        for(i = 0; i < len; i++) {
            c = buf[i];
            if(c == '#') {
                break;
            }

            if(c == ' ') {
                continue;
            }

            if(c == '\n') {
                break;
            }

            if(c == '=') {
                break;
            }
            key += c;
        }

        if(c == '=') {
            i++;
            for(i; i < len; i++) {
                c = buf[i];
                if(c == '#') {
                    break;
                }

                if(c == '\n') {
                    break;
                }

                if(c == ' ') {
                    continue;
                }
                val += c;
            }
        }

        if(!key.empty() && !val.empty()) {
            _M_config_map.insert({key, val});
        }
    }
}

std::string RpcConfig::get(std::string key)
{ 
    auto it = _M_config_map.find(key);
    if(it == _M_config_map.end()) {
        return "";
    }
    return it->second;
}

} // namespace myrpc