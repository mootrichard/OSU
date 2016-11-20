cmake_minimum_required(VERSION 3.6)
project(smallsh C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES main.c)
add_executable(smallsh ${SOURCE_FILES})