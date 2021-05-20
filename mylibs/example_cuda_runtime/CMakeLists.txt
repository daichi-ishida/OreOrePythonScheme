set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(RUNTIME_OBJ "${TARGET_NAME}_RTOBJ")

set(PROJECT_DEFINITION
    _OPENMP 
    _USE_MATH_DEFINES
)

# ------------------------------------------------------------------------------
# Compile runtime kernel
# ------------------------------------------------------------------------------
find_package(CUDAToolkit 11 REQUIRED)

add_subdirectory("runtime_kernels")

# ------------------------------------------------------------------------------
# Create a CXX Library
# ------------------------------------------------------------------------------
find_package(fmt CONFIG REQUIRED)

file(GLOB CXX_SOURCES src/*.cpp)

add_library(${TARGET_CXXLIB_NAME} ${CXX_SOURCES})

target_link_libraries(${TARGET_CXXLIB_NAME} PUBLIC fmt::fmt ${RUNTIME_OBJ})
target_include_directories(${TARGET_CXXLIB_NAME} PUBLIC ${COMMON_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/include)


target_compile_features(${TARGET_CXXLIB_NAME} PUBLIC cxx_std_14)
target_compile_options(${TARGET_CXXLIB_NAME} PUBLIC
    # warnings
    $<$<CXX_COMPILER_ID:Clang>:-Wall -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic>
    $<$<CXX_COMPILER_ID:GCC>:-pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused>
    $<$<CXX_COMPILER_ID:MSVC>:/W4>

    # flags for each build type
    $<$<CXX_COMPILER_ID:Clang>:
        $<$<CONFIG:Release>:-O3>                  # Release
        $<$<CONFIG:Debug>:-O0 -g>                 # Debug
        $<$<CONFIG:RelWithDebgInfo>:-O3 -g>       # RelWithDebInfo
    >
    $<$<CXX_COMPILER_ID:GCC>:
        $<$<CONFIG:Release>:-O3>                  # Release
        $<$<CONFIG:Debug>:-O0 -g>                 # Debug
        $<$<CONFIG:RelWithDebgInfo>:-O3 -g>       # RelWithDebInfo
    >

    $<$<CXX_COMPILER_ID:MSVC>: 
        $<$<CONFIG:Release>:/O2 /Zi /MP>          # Release
        $<$<CONFIG:Debug>:/Od /ZI /MP>            # Debug
        $<$<CONFIG:RelWithDebgInfo>:/O2 /ZI /MP>  # RelWithDebInfo
    >
)

target_compile_definitions(${TARGET_CXXLIB_NAME} PUBLIC
    $<$<CONFIG:Debug>:DEBUG>          # Debug
    $<$<NOT:$<CONFIG:Debug>>:NDEBUG>  # else
    ${PROJECT_DEFINITION}
)

add_dependencies(${TARGET_CXXLIB_NAME} ${RUNTIME_OBJ})

# ------------------------------------------------------------------------------
# Bind the CXX library to a Python module
# ------------------------------------------------------------------------------
pybind11_add_module(${TARGET_NAME} mymodule.cpp)
target_link_libraries(${TARGET_NAME} PRIVATE ${TARGET_CXXLIB_NAME})
target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
