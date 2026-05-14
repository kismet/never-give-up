cmake_minimum_required(VERSION 3.0)
project(never_give_up)

set(CMAKE_CXX_STANDARD 20)

add_executable(never_give_up main.cpp
        includes/libs.h
        includes/types.h
        sources/libs.cpp
        includes/libs.h)
