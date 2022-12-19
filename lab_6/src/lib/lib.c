#include "lib.h"
#include <stdio.h>

const char cons[CONS_LEN] = 
{
    'b', 'c', 'd', 'f', 
    'g', 'h', 'j', 'k', 
    'l', 'm', 'n', 'p', 
    'q', 'r', 's', 't', 
    'v', 'w', 'x', 'z',

    'B', 'C', 'D', 'F',
    'G', 'H', 'J', 'K',
    'L', 'M', 'N', 'P',
    'Q', 'R', 'S', 'T',
    'V', 'W', 'X', 'Z'
};

void print_list(node* head) {
    node* cur = head;

    while (cur != NULL) {
        printf("%c", cur->sym);
        cur = cur->next;
    }
    printf("\n");
}

void push_back(node** prev, char sym) {
    node* new = (node *) malloc(sizeof(node));
    node* last = *prev;

    new->sym = sym;
    new->next = NULL;

    if (*prev == NULL) {
        *prev = new;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new;
}

void free_list(node** head) {
    node* cur = *head;
    node* next;

    while(cur != NULL) {
        next = cur->next;
        free(cur);
        cur = next;
    }

    *head = NULL;
}

int readline(const char* prompt, node** list) {
    printf("%s", prompt);
    char ch;

    while ((ch = getchar()) != '\n') {
        if (ch == EOF) {
            return EXIT_FAILURE;
        }

        push_back(list, ch);
    }

    return EXIT_SUCCESS;
}

int find(char c) {
    for(size_t i = 0; i < CONS_LEN; ++i) {
        if (cons[i] == c) return 0;
    }

    return 1;
}
