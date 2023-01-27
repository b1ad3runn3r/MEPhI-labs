CMAKE_MINIMUM_REQUIRED(VERSION 3.20)

project("Lab 3" C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -gdwarf-4 -Wall -Wextra -Wpedantic -fno-omit-frame-pointer")

set(SRC src)
set(LIB lib)

FILE(GLOB LIB_SRC ${LIB}/*.c)

add_executable(lab3 main.c ${LIB_SRC})
