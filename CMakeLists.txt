cmake_minimum_required(VERSION 3.17)

set(PROJECT_NAME pybindtest)
set(TARGET_APP "APP")

set(TARGET_NAME "example_cuda")
set(TARGET_CXXLIB_NAME ${TARGET_NAME}_CXXLIB)
set(TARGET_CXXLIB_PTX ${TARGET_CXXLIB_NAME}_PTX)

project(${PROJECT_NAME})

# ------------------------------------------------------------------------------
# Add Google Test
# ------------------------------------------------------------------------------
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# ------------------------------------------------------------------------------
# Set global variables
# ------------------------------------------------------------------------------
set(COMMON_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/common")
set(COMMON_LIBRARIES)

# ------------------------------------------------------------------------------
# Set Additional Find.cmake directory
# ------------------------------------------------------------------------------
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

# ------------------------------------------------------------------------------
# Add subdirectory
# ------------------------------------------------------------------------------
add_subdirectory("extern/pybind11")
add_subdirectory("mylibs")
add_subdirectory("test")
add_subdirectory("app")

add_dependencies(${TARGET_APP} ${TARGET_CXXLIB_NAME})
