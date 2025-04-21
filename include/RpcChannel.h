#pragma once

#include <google/protobuf/service.h>

namespace myrpc
{

namespace gp = google::protobuf;

class RpcChannel : public gp::RpcChannel
{
public:
    void CallMethod(const gp::MethodDescriptor *method,
                    gp::RpcController *controller,
                    const gp::Message *request,
                    gp::Message *response,
                    gp::Closure *done);
};


} // myrpc