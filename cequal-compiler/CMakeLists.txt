cmake_minimum_required(VERSION 3.12)
project(CEqual)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(CEqual src/main.cpp)