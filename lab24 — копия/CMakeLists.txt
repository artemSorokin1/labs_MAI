cmake_minimum_required(VERSION 3.25)
project(lab24)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab24 main.cpp libs/Stack.cpp libs/Tree.cpp)
