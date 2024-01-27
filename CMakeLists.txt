cmake_minimum_required(VERSION 3.15)
project(pybindtest)

link_directories(${PROJECT_SOURCE_DIR})

add_library(lib_test SHARED library.c)

add_executable(main library_test.c)
target_link_libraries(main lib_test)

find_package(pybind11 REQUIRED)
pybind11_add_module(add_c addlib_interface.cpp)
target_link_libraries(add_c PUBLIC lib_test)