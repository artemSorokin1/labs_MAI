cmake_minimum_required(VERSION 3.25)
project(test)

set(CMAKE_CXX_STANDARD 17)

add_executable(test List.cpp main.cpp variant.cpp)
