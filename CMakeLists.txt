cmake_minimum_required(VERSION 3.13)
project(myTinyRPC)

set(CMAKE_VERBOSE_MAKEFILE off)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)
set(CMAKE_CXX_STANDARD 20)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/third-party/myTinyMuduo/include)

link_directories(${PROJECT_SOURCE_DIR}/lib ${PROJECT_SOURCE_DIR}/third-party/myTinyMuduo/lib)

find_package(Protobuf)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(examples)