cmake_minimum_required(VERSION 3.12)
project(algs4c C)

enable_testing()

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

# Add array_structures library
add_subdirectory(stack)
add_subdirectory(queue)
add_subdirectory(unity)
add_subdirectory(unit_test)

add_executable(algs4c main.c)
# Link to libraries
target_link_libraries(algs4c stack)