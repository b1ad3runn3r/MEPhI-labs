CMAKE_MINIMUM_REQUIRED(VERSION 3.20)

project("Lab 1" C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -gdwarf-4 -Wall -Wextra -Wpedantic -fno-omit-frame-pointer")

add_executable(lab1 main.c)
