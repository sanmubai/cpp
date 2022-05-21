cmake_minimum_required(VERSION 3.21)
project(cpp C)

set(CMAKE_C_STANDARD 99)

add_executable(cpp main.c include/linklist.h linklist/linklist.c linklist/data.c include/data.h)
