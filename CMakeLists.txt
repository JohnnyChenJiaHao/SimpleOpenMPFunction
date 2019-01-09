cmake_minimum_required(VERSION 3.12)
project(A0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

include_directories(.)

add_executable(A0
        a0.cpp
        a0.hpp
        a0.txt
        Makefile)
