cmake_minimum_required(VERSION 3.31)
project(Thorn)

set(CMAKE_CXX_STANDARD 11)

add_executable(Thorn src/Main.cpp
        src/frontend/lex.cpp
        src/frontend/lex.h)
