project(provider)

set(SRC_LIST CalleeUserService.cc ../user.pb.cc)

add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(${PROJECT_NAME} ${PROTOBUF_LIBRARIES} myrpc)