cmake_minimum_required(VERSION 2.8)

add_compile_options(-std=c++11)


project(picture)
include_directories(include)

link_directories(${PROJECT_SOURCE_DIR}/lib)
add_executable(picture test.cpp)
target_link_libraries(picture libexiv2.so)




#add_library(picture libexiv2.so)
