cmake_minimum_required(VERSION 3.6)

project(asio_test)

set(CMAKE_C_STANDERED 99)
set(CMAKE_CXX_STANDERED 11)

add_definitions(-DASIO_STANDALONE)
include_directories(third/asio/include)

add_executable(demo asio_timer_test.cpp)