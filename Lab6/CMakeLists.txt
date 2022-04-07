cmake_minimum_required(VERSION 3.21)
project(Lab6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab6
        App.cpp
        Colectie.cpp
        Colectie.h
        IteratorColectie.cpp
        IteratorColectie.h
        TestExtins.cpp
        TestExtins.h
        TestScurt.cpp
        TestScurt.h)
