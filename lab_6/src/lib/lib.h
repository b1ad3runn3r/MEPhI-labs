#pragma once

#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>

#define CONS_LEN 42

typedef struct node{
    char sym;
    struct node* prev;
    struct node* next;
} node;

void print_list(node* list);

void push_back(node** list, char sym);

void free_list(node** list);

int readline(const char* prompt, node** list);

int is_cons(char c);

void remove_node(node** list, node* del);

void remove_cons(node** list);

#endif
