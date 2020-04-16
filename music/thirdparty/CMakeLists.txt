project(other_project)

add_subdirectory(libconfig)

include(ExternalProject)

set(CONFIG_ROOT ${CMAKE_SOURCE_DIR}/deps)
set(CONFIG_SOURCE_DIR ${CMAKE_SOURCE_DIR}/config)
set(PREFIX_ROOT ${CMAKE_SOURCE_DIR}/thirdparty/libconfig/build)
#set(CONFIG_MAKE)  

message("child==================== ${CMAKE_SOURCE_DIR}")

ExternalProject_Add(config 
        PREFIX              libconfig
        SOURCE_DIR          ${CMAKE_SOURCE_DIR}/thirdparty/libconfig
        CMAKE_ARGS          -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/deps
    )