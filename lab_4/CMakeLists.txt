CMAKE_MINIMUM_REQUIRED(VERSION 3.20)

project("Lab 4" C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -gdwarf-4 -Wall -Wextra -Wpedantic -fno-omit-frame-pointer")

set(SRC src)
set(LIB ${SRC}/lib)

FILE(GLOB LIB_SRC ${LIB}/*.c)

add_executable(lab4_self ${SRC}/main.c ${LIB_SRC})

add_executable(lab4_readline ${SRC}/main.c ${LIB_SRC})
target_link_libraries(lab4_readline readline)
set_target_properties(lab4_readline PROPERTIES COMPILE_FLAGS "-DREADLINE")

