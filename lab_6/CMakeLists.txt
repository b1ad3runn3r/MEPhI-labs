CMAKE_MINIMUM_REQUIRED(VERSION 3.20)

project("Lab 6" C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -gdwarf-4 -Wall -Wextra -Wpedantic -fno-omit-frame-pointer")

set(SRC src)
set(LIB ${SRC}/lib)

add_executable(lab6 ${SRC}/main.c ${LIB}/lib.c)