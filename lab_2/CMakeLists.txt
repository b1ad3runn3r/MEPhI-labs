CMAKE_MINIMUM_REQUIRED(VERSION 3.20)

project("Lab 2" C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -gdwarf-4 -Wall -Wextra -Wpedantic -fno-omit-frame-pointer")

add_executable(lab2_1 lab2_1.c)
target_link_libraries(lab2_1 m)

add_executable(lab2_2 lab2_2.c)
target_link_libraries(lab2_2 m)
