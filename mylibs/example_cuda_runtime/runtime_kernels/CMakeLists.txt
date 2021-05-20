# ------------------------------------------------------------------------------
# Compile Runtime Cuda files
# ------------------------------------------------------------------------------
enable_language(CUDA)

file(GLOB _RUNTIME_KERNEL_SOURCES *.cu)

add_library(${RUNTIME_OBJ} STATIC ${_RUNTIME_KERNEL_SOURCES})

target_link_libraries(${RUNTIME_OBJ} PRIVATE CUDA::cudart)
set_target_properties(${RUNTIME_OBJ} PROPERTIES CUDA_SEPARABLE_COMPILATION ON CUDA_RESOLVE_DEVICE_SYMBOLS ON POSITION_INDEPENDENT_CODE ON)
target_compile_features(${RUNTIME_OBJ} PUBLIC cxx_std_14)
target_compile_options(${RUNTIME_OBJ} PRIVATE 
        # # --use_fast_math

        # # Maxwell Gen2
        # "$<$<COMPILE_LANGUAGE:CUDA>:SHELL:-gencode arch=compute_52,code=sm_52>"
        # # Pascal
        # "$<$<COMPILE_LANGUAGE:CUDA>:SHELL:-gencode arch=compute_61,code=sm_61>"
        # # Volta
        # "$<$<COMPILE_LANGUAGE:CUDA>:SHELL:-gencode arch=compute_70,code=sm_70>"
        # # Turing
        # "$<$<COMPILE_LANGUAGE:CUDA>:SHELL:-gencode arch=compute_75,code=sm_75>"
        # # Ampere
        # "$<$<COMPILE_LANGUAGE:CUDA>:SHELL:-gencode arch=compute_86,code=sm_86>"
)
target_include_directories(${RUNTIME_OBJ}
    PRIVATE $<TARGET_PROPERTY:INTERFACE_INCLUDE_DIRECTORIES> ${COMMON_INCLUDE_DIRS})

target_compile_definitions(${RUNTIME_OBJ} PUBLIC
    $<$<CONFIG:Debug>:DEBUG>          # Debug
    $<$<NOT:$<CONFIG:Debug>>:NDEBUG>  # else
    ${PROJECT_DEFINITION}
)
