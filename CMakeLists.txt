cmake_minimum_required(VERSION 3.26)
project(ManagingThreads)

set(CMAKE_CXX_STANDARD 17)

add_executable(ManagingThreads main.cpp
        ParallelAccumulate.cpp)
