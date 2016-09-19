cmake_minimum_required(VERSION 2.8.9)
project(Hanoi)

include_directories(include)

set(SOURCES src/Hanoi.cpp src/main.cpp)

add_executable(Hanoi ${SOURCES})
