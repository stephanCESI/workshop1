cmake_minimum_required(VERSION 3.26)
project(Workshop_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Workshop_1 main.cpp
        heros.cpp
        heros.h
        creature.cpp
        creature.h
        jeu.cpp
        jeu.h
        interface.cpp
        interface.h)
