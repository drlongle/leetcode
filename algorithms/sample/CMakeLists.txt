cmake_minimum_required(VERSION 3.16)
project(solution)

set(CMAKE_CXX_STANDARD 20)

add_executable(solution solution.cpp)

set (CMAKE_INSTALL_BINDIR /home/long/temp)
set (CMAKE_INSTALL_LIBDIR /home/long/temp)
install(TARGETS solution)
