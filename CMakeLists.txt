cmake_minimum_required(VERSION 3.10)
project(Concurrency)

set(CMAKE_CXX_STANDARD 11)




add_executable(Concurrency main.cpp msg_queue.cpp msg_queue.h timer.h)
TARGET_LINK_LIBRARIES( Concurrency pthread)