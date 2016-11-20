cmake_minimum_required(VERSION 3.6)
project(cs344_project4)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c)
add_executable(cs344_project4 ${SOURCE_FILES})