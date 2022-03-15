cmake_minimum_required(VERSION 3.21)
project(Proiect_C__)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Proiect_C__
        App.cpp
        DO.cpp
        DO.h
        Iterator.cpp
        Iterator.h
        TestExtins.cpp
        TestExtins.h
        TestScurt.cpp
        TestScurt.h)
