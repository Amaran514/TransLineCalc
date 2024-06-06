cmake_minimum_required(VERSION 3.28)
project(TransLineCalc)

set(CMAKE_CXX_STANDARD 17)

add_executable(TransLineCalc main.cpp Complex.h Complex.cpp TransmissionLine.h TransmissionLine.cpp clipp.h)

add_executable(test test.cpp Complex.h Complex.cpp TransmissionLine.h TransmissionLine.cpp)
