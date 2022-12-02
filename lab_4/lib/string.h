#pragma once
#ifndef STRING_H
#define STRING_H
#include <stdlib.h>
#include <stdio.h>

#define CHUNK 100

typedef unsigned long size_t;

size_t  my_strlen(char*);

void    my_memcpy(char*, char*, size_t);

void    swap(char**);

char*   remove_spaces(char*);

char*   my_readline(char*);

#endif
