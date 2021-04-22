function(add_unit_test name)
  add_executable(${name} ${name}.cpp)
  # TODO: include target header from name
  target_include_directories(${name} PRIVATE ${COMMON_INCLUDE_DIRS})
  # TODO: set target cxx library from name
  target_link_libraries(${name} ${TARGET_CXXLIB_NAME} gtest_main)
  add_test(NAME ${name} COMMAND ${name})
endfunction()

add_unit_test(testA)

add_dependencies(testA ${TARGET_CXXLIB_NAME})
