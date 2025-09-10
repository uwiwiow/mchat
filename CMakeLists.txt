cmake_minimum_required(VERSION 3.29)
project(mchat C)

set(CMAKE_C_STANDARD 23)

add_executable(mchat main.c
        morseBinaryTree.c
        morseBinaryTree.h
)

find_package(raylib REQUIRED)

target_link_libraries(mchat raylib)