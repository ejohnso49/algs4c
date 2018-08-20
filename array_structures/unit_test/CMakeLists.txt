add_executable(testStack test_stack.c)
target_link_libraries(testStack unity)
target_link_libraries(testStack array_structures)
add_test(testStack testStack)