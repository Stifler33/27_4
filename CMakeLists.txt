cmake_minimum_required(VERSION 3.20)
project(27_4)

set(CMAKE_CXX_STANDARD 14)

add_executable(27_4 task4.cpp mainRandFunction.h)
target_sources(27_4 PUBLIC RandomFunction.cpp)
