cmake_minimum_required(VERSION 3.20)
project(Insertion_Sort)

set(CMAKE_CXX_STANDARD 20)

add_executable(Insertion_Sort
        main.cpp
        SortingInsertion.cpp   # must include .cpp file
)
