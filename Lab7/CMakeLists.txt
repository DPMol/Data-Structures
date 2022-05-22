cmake_minimum_required(VERSION 3.21)
project(Lab7)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab7
        App.cpp
        IteratorMDO.cpp
        IteratorMDO.h
        MDO.cpp
        MDO.h
        TestExtins.cpp
        TestExtins.h
        TestScurt.cpp
        TestScurt.h)
