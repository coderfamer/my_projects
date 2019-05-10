# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project (testcmake)
set(SRC_LIST testcmake.cpp)

add_executable(demo ${SRC_LIST})

if (WIN32)
	add_definitions(-DWIN32_BUILD)
elseif (WIN64)
	add_definitions(-DWIN64_BUILD)
endif()

if 

