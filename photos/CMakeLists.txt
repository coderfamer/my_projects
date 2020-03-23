cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

#project name
project(photo LANGUAGES CXX)

add_executable(photo main.cpp)
add_compile_options(-std=c++11)

set(LINK_DIR ./libs/)
set(INC_DIR ./include/)
include_directories(${INC_DIR})
target_link_libraries(photo
libexiv2.so)


# set exe output path
#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)