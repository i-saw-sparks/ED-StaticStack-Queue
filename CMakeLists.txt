cmake_minimum_required(VERSION 3.15)
project(PilaColaEstatica)

set(CMAKE_CXX_STANDARD 11)

add_executable(PilaColaEstatica main.cpp Stack.h Queue.h PostfixExp.cpp PostfixExp.h Menu.cpp Menu.h)