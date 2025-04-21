#include "RpcChannel.h"

namespace myrpc
{

void RpcChannel::CallMethod(const gp::MethodDescriptor *method,
                    gp::RpcController *controller,
                    const gp::Message *request,
                    gp::Message *response,
                    gp::Closure *done)
{

}

} // myrpc