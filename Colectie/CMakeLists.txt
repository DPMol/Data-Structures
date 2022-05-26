cmake_minimum_required(VERSION 3.21)
project(Colectie)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Colectie
        App.cpp
        Colectie.cpp
        Colectie.h
        IteratorColectie.cpp
        IteratorColectie.h
        TestExtins.cpp
        TestExtins.h
        TestScurt.cpp
        TestScurt.h)
