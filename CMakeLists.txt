cmake_minimum_required(VERSION 3.8)
project(Data_structure)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c stack.c stack.h "dichotomy algorithm.c" "dichotomy algorithm.h" lqueue.c lqueue.h)
add_executable(Data_structure ${SOURCE_FILES} lqueue.c lqueue.h)