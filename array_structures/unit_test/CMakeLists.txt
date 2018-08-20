add_executable(testStack test_stack.c)
target_link_libraries(testStack unity)
add_test(testStack testStack)