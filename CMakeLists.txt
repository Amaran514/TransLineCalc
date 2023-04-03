cmake_minimum_required(VERSION 3.25)
project(TransLineCalc)

set(CMAKE_CXX_STANDARD 20)

add_executable(TransLineCalc main.cpp Complex.h Complex.cpp TransmissionLine.h TransmissionLine.cpp clipp.h)

add_executable(test test.cpp Complex.h Complex.cpp TransmissionLine.h TransmissionLine.cpp)
