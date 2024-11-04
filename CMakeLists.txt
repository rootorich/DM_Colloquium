cmake_minimum_required(VERSION 3.23)
project(DM_Colloquium)

set(CMAKE_CXX_STANDARD 23)

file(GLOB SOURCES
        project_lib/*.h
        project_lib/*.cpp
        tests/.h
        tests/*.cpp
        )


add_executable(DM_Colloquium ${SOURCES}
        main.cpp)
