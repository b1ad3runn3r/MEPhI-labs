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

void print_list(node* list) {
    node* ptr = list;
    while (ptr != NULL) {
        printf("%c", ptr->sym);
        ptr = ptr->next;
    }
    printf("\n");
}

void push_back(node** list, char sym) {
    node* new = (node *) malloc(sizeof(node));
    
    node* last = NULL;
    new->next = NULL;
    new->prev = NULL;
    new->sym = sym;

    if (*list == NULL) {
        *list = new;
    }
    else {
        last = *list;
        while (last->next != NULL) {
            last = last->next;
        }

        last->next = new;
        new->prev = last;
    }
}


void free_list(node** list) {
    node* cur = *list;
    node* next;

    while(cur != NULL) {
        next = cur->next;
        free(cur);
        cur = next;
    }
    *list = NULL;
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
    push_back(list, '\0');

    return EXIT_SUCCESS;
}

int find(char c) {
    for(size_t i = 0; i < CONS_LEN; ++i) {
        if (cons[i] == c) return 0;
    }

    return 1;
}

void remove_node(node** list, node* del) {
    if (*list == NULL || del == NULL) {
        return;
    }

    if (del == *list) {
        *list = del->next;
    }

    if (del->prev != NULL) {
        del->prev->next = del->next;
    }

    if (del->next != NULL) {
        del->next->prev = del->prev;
    }
    
    free(del);
}

void remove_cons(node** list) {
    node* cur = *list;
    node* next;
    
    while(cur != NULL) {
        if (!find(cur->sym)) {
            next = cur->next;
            remove_node(list, cur);
            cur = next;
        }
        else {
            cur = cur->next;
        }
    }
}
