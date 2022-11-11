cmake_minimum_required(VERSION 3.22)
project(model_inference_study)

set(CMAKE_CXX_STANDARD 14)

add_executable(model_inference_study main.cpp FunctionGenerator.hpp)
