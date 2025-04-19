#pragma once

#include <unordered_map>
#include <string>

namespace myrpc
{

/**
 * @brief 读取配置文件类 
 */
class RpcConfig
{
public:

    /**
     * @brief 加载配置文件
     */
    void load(const std::string& config_file);
    
    /**
     * @brief 获取key对应的value
     */
    std::string get(std::string key);

private:
    
    std::unordered_map<std::string, std::string> _M_config_map;
 
};

} // namespace myrpc