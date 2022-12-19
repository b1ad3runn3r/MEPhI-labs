#pragma once

#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>

#define CONS_LEN 40

typedef struct node{
    char sym;
    struct node* next;
} node;

void print_list(node* head);

void push_back(node** prev, char sym);

void free_list(node** head);

int readline(const char* prompt, node** list);

int find(char c);

#endif
