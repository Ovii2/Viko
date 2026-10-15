cmake_minimum_required(VERSION 4.3)
project(02_students_grading_system)

set(CMAKE_CXX_STANDARD 23)

add_executable(02_students_grading_system main.cpp)

if(MSVC)
    target_compile_options(02_students_grading_system PRIVATE /utf-8)
endif()