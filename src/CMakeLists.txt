project(myrpc)

aux_source_directory(. SRC_LIST)

add_library(${PROJECT_NAME} SHARED ${SRC_LIST})

target_link_libraries(${PROJECT_NAME} ${PROTOBUF_LIBRARIES})

target_link_libraries(${PROJECT_NAME} mymuduo)