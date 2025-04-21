#pragma once

#include <google/protobuf/service.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>

namespace myrpc
{

namespace gp = google::protobuf;

class RpcChannel : public gp::RpcChannel
{
public:

    /**
     * @brief 对数据进行序列化
     */
    void CallMethod(const gp::MethodDescriptor *method,
                    gp::RpcController *controller,
                    const gp::Message *request,
                    gp::Message *response,
                    gp::Closure *done);
};


} // myrpc