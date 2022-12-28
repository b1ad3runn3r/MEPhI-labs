CMAKE_MINIMUM_REQUIRED(VERSION 3.20)

project("Lab 5" C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -gdwarf-4 -Wall -Wextra -Wpedantic -fno-omit-frame-pointer")

set(SRC src)
set(LIB ${SRC}/lib)

FILE(GLOB LIB_SRC ${LIB}/*.c)

add_executable(lab5_1 ${SRC}/main_1.c ${LIB_SRC})
add_executable(lab5_2 ${SRC}/main_2.c ${LIB_SRC})
