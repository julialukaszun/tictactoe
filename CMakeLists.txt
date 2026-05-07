cmake_minimum_required(VERSION 3.27)
project(tictactoe)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib CONFIG REQUIRED)

add_executable(tictactoe main.cpp
        button.cpp
        button.h)

target_link_libraries(tictactoe PRIVATE raylib)


