cmake_minimum_required(VERSION 3.2)

project(Builder)

add_library(BuilderLib Builder.hpp Builder.cpp)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE BuilderLib)