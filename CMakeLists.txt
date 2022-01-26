cmake_minimum_required(VERSION 3.21)
project(STCP_AED_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(STCP_AED_project main.cpp menu.cpp menu.h graph.h filereader.cpp filereader.h)
