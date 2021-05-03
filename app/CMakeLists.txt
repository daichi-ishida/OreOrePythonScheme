# ------------------------------------------------------------------------------
# Configure Main Projects
# ------------------------------------------------------------------------------
add_executable(${TARGET_APP})

# find_package(XXX REQUIRED)

file(GLOB_RECURSE CXX_SOURCES *.cpp)
target_sources(${TARGET_APP} PRIVATE ${CXX_SOURCES})

target_link_libraries(${TARGET_APP} ${TARGET_CXXLIB_NAME})

# ------------------------------------------------------------------------------
# Set compiler options
# ------------------------------------------------------------------------------

target_compile_features(${TARGET_APP} PUBLIC cxx_std_14)
target_compile_options(${TARGET_APP} PUBLIC
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

target_compile_definitions(${TARGET_APP} PUBLIC
    $<$<CONFIG:Debug>:DEBUG>          # Debug
    $<$<NOT:$<CONFIG:Debug>>:NDEBUG>  # else
)

# ------------------------------------------------------------------------------
# Post Process (copy PTX files)
# ------------------------------------------------------------------------------
add_custom_command(TARGET ${TARGET_APP} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:${TARGET_APP}>/PTXs/
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_OBJECTS:${TARGET_CXXLIB_PTX}> $<TARGET_FILE_DIR:${TARGET_APP}>/PTXs/ COMMAND_EXPAND_LISTS)

add_custom_command(TARGET ${TARGET_APP} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_SOURCE_DIR}/PTXs/
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_OBJECTS:${TARGET_CXXLIB_PTX}> ${CMAKE_CURRENT_SOURCE_DIR}/PTXs/ COMMAND_EXPAND_LISTS)