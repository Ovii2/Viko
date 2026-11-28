cmake_minimum_required(VERSION 4.4)
project(04_restaurant_accounting_system)

set(CMAKE_CXX_STANDARD 23)

add_executable(04_restaurant_accounting_system main.cpp)

if (MSVC)
    target_compile_options(04_restaurant_accounting_system PRIVATE /utf-8)
endif ()
