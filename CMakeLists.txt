cmake_minimum_required(VERSION 3.16)
project(parser)

set(CMAKE_CXX_STANDARD 14)

add_executable(parser main.cpp Operator.cpp Operator.h Parser.cpp Parser.h Stack.h)