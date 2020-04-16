cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(music LANGUAGES C CXX)


#set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 11)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(SOURCE_FILES src/main.cpp) 
set(ROOT_DEPS_DIR ${CMAKE_SOURCE_DIR})
set(STAGED_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/deps)

find_package(Threads)

include(config)

execute_process(
    COMMAND cmake --build . ${CMAKE_SOURCE_DIR}/thirdparty/libconfig
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/thirdparty/libconfig
)




#include(config)

#find_package(config REQUIRED)   

# if (NOT CONFIG_FOUND)
#     message("--------not found  ${CONFIG_INCLUDE_DIRS}")
#     add_custom_target(third)
#     include(ExternalProject)
#     ExternalProject_Add(config 
#         PREFIX "libconfig"
#         SOURCE_DIR 
#             ${CMAKE_SOURCE_DIR}/thirdparty/libconfig
#         CMAKE_ARGS
#             -DCMAKE_INSTALL_PREFIX=${STAGED_INSTALL_PREFIX}
#         STEP_TARGETS 
#             build
#         BUILD_COMMAND     
#             make   
#         #BINARY_DIR "${CMAKE_SOURCE_DIR}/libs"
#         #INSTALL_DIR "${CMAKE_SOURCE_DIR}/libs"
#         INSTALL_COMMAND    
#             make install
#     )

#     message("not found ----------------")
# else()
#     message("--------found")
# endif()



#include_directories(${CMAKE_SOURCE_DIR}/include/)
add_executable(music ${SOURCE_FILES})
target_include_directories(music 
    PRIVATE 
        ${CMAKE_SOURCE_DIR}/include
        ${CONFIG_INCLUDE_DIRS}
    )
target_link_libraries(music 
    PRIVATE
        ${CMAKE_THREAD_LIBS_INIT}
        ${CONFIG_LIBRARIES}
    )


