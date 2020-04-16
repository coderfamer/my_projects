if (NOT CONFIG_ROOT)
    set(CONFIG_ROOT ${ROOT_DEPS_DIR}/deps)
endif()

if (NOT CONFIG_ROOT)
    find_path(_CONFIG_ROOT NAMES include/libconfig.hh)
else()
    set(_CONFIG_ROOT ${CONFIG_ROOT})
endif()

find_path(CONFIG_INCLUDE_DIRS
    NAMES libconfig.hh
    HINTS ${_CONFIG_ROOT}/include
)

find_library(CONFIG_LIBRARIES
    NAMES
        libconfig.so
    HINTS
        ${_CONFIG_ROOT}/lib64
    )

# message(STATUS "==================="  ${CONFIG_ROOT})
# message(STATUS "==================="  ${_CONFIG_ROOT})
# message(STATUS "==================="  ${CONFIG_INCLUDE_DIRS})
# message(STATUS "==================="  ${CONFIG_LIBRARIES})