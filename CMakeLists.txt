cmake_minimum_required(VERSION 3.21)
project(STCP_AED_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(STCP_AED_project main.cpp filereader.cpp filereader.h distance_graph.cpp distance_graph.h minHeap.h lesschanges_graph.cpp lesschanges_graph.h)
