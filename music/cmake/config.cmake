include(ExternalProject)

set(CONFIG_ROOT ${CMAKE_SOURCE_DIR}/deps)
set(CONFIG_SOURCE_DIR ${CMAKE_SOURCE_DIR}/thirdparty/config)
#set(CONFIG_MAKE)  

ExternalProject_Add(config 
        PREFIX              libconfig
        SOURCE_DIR          ${CMAKE_SOURCE_DIR}/thirdparty/libconfig
        CMAKE_ARGS          -DCMAKE_INSTALL_PREFIX=${STAGED_INSTALL_PREFIX}
    )