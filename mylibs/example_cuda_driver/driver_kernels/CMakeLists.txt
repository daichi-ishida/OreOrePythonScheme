# ------------------------------------------------------------------------------
# Configure PTX Projects
# ------------------------------------------------------------------------------
enable_language(CUDA)
file(GLOB _DRIVER_KERNEL_SOURCES *.cu)

add_library(${TARGET_CXXLIB_PTX} OBJECT ${_DRIVER_KERNEL_SOURCES})
set_target_properties(${TARGET_CXXLIB_PTX} PROPERTIES CUDA_PTX_COMPILATION ON)
target_compile_features(${TARGET_CXXLIB_PTX} PUBLIC cuda_std_14)
# target_compile_options(${TARGET_CXXLIB_PTX} PRIVATE 
#         # --use_fast_math

#         # Maxwell Gen2
#         "$<$<COMPILE_LANGUAGE:CUDA>:SHELL:-gencode arch=compute_52,code=sm_52>"
#         # Pascal
#         "$<$<COMPILE_LANGUAGE:CUDA>:SHELL:-gencode arch=compute_61,code=sm_61>"
#         # Volta
#         "$<$<COMPILE_LANGUAGE:CUDA>:SHELL:-gencode arch=compute_70,code=sm_70>"
#         # Turing
#         "$<$<COMPILE_LANGUAGE:CUDA>:SHELL:-gencode arch=compute_75,code=sm_75>"
#         # Ampere
#         "$<$<COMPILE_LANGUAGE:CUDA>:SHELL:-gencode arch=compute_86,code=sm_86>"
# )
target_include_directories(${TARGET_CXXLIB_PTX}
    PRIVATE $<TARGET_PROPERTY:INTERFACE_INCLUDE_DIRECTORIES> ${COMMON_INCLUDE_DIRS})

