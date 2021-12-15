cmake_minimum_required(VERSION 3.21)
project(trs_completion)

set(CMAKE_CXX_STANDARD 17)

add_executable(trs_completion main.cpp Trs.cpp Trs.h Term.cpp Term.h)
