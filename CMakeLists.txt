# cmake_minimum_required(VERSION <specify CMake version here>)
project(Data_Structures)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Data_Structures
        AvlTree/AvlTree.cpp
        AvlTree/AvlTree.h
        main.cpp
        Heaps/Heap.cpp Heaps/Heap.h HashTable/HashEntry.cpp HashTable/HashEntry.h HashTable/HashTable.cpp HashTable/HashTable.h Graph/Graph.cpp Graph/Graph.h)
