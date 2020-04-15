cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(music LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES src/main.cpp) 

find_package(Threads)



#include_directories(${CMAKE_SOURCE_DIR}/include/)
add_executable(music ${SOURCE_FILES})
target_include_directories(music PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(music ${CMAKE_THREAD_LIBS_INIT})

message("${CMAKE_BINARY_DIR}/thirdparty/libconfig")

include(ExternalProject)
ExternalProject_Add(config 
    PREFIX "libconfig"
    SOURCE_DIR "${CMAKE_SOURCE_DIR}/thirdparty/libconfig"
    BUILD_COMMAND ""
    BINARY_DIR "${CMAKE_SOURCE_DIR}/libs"
    INSTALL_DIR "${CMAKE_SOURCE_DIR}/libs"
    INSTALL_COMMAND "make"
    
)

#add_subdirectory(thirdparty/libconfig)
