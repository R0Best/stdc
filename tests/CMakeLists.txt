add_executable(type_enum_test type_enum_test.c)
target_link_libraries(type_enum_test PRIVATE stdc)
add_test(NAME type_enum_test COMMAND type_enum_test)
