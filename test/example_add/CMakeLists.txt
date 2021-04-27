function(add_unit_test name)
  add_executable(${name} ${name}.cpp)
  target_link_libraries(${name} ${TARGET_CXXLIB_NAME} gtest_main)
  add_test(NAME ${name} COMMAND ${name})
endfunction()

add_unit_test(testA)

add_dependencies(testA ${TARGET_CXXLIB_NAME})
