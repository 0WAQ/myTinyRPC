project(protobuf_unittest)

aux_source_directory(. SRC)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} ${PROTOBUF_LIBRARIES})