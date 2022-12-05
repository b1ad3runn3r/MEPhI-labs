#pragma once
#ifndef STRING_H
#define STRING_H

#define CHUNK 100

typedef unsigned long size_t;

size_t  my_strlen(const char* str);

void    my_memcpy(char* dst, char* src, size_t n);

char*   my_readline(const char* prompt);

#endif
