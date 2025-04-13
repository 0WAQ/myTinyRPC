#include <iostream>

#include "protobuf_unittest.pb.h"

namespace pb = protobuf_unittest;


int main()
{
    pb::LoginResponse res;
    pb::ResultCode* rc = res.mutable_result();
    rc->set_errcode(1);
    rc->set_message("OK");
    res.set_success(false);
    
    pb::GetFriendListsResponse res1;
    pb::ResultCode* rc1 = res1.mutable_result();
    rc1->set_errcode(0);
    rc1->set_message("FAILED");
    pb::User* user1 = res1.add_friend_list();
    user1->set_name("bwb");
    user1->set_age(19);
    user1->set_sex(pb::User::MALE);
    std::cout << res1.friend_list_size() << std::endl;

    return 0;
}