# cmake_minimum_required(VERSION <specify CMake version here>)
project(Data_Structures)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Data_Structures
        AvlTree.cpp
        AvlTree.h
        main.cpp
        Heap.cpp Heap.h HashEntry.cpp HashEntry.h HashTable.cpp HashTable.h Graph.cpp Graph.h)
