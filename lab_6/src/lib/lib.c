#include "lib.h"
#include <stdio.h>

const char cons[CONS_LEN] = 
{
    'b', 'c', 'd', 'f', 'g', 'h', 'j', 
    'k', 'l', 'm', 'n', 'p', 'q', 'r', 
    's', 't', 'v', 'w', 'x', 'y', 'z',

    'B', 'C', 'D', 'F', 'G', 'H', 'J', 
    'K', 'L', 'M', 'N', 'P', 'Q', 'R', 
    'S', 'T', 'V', 'W', 'X', 'Y', 'Z'
};

void print_list(node** list) {
    node* ptr = *list;
    printf("\"");
    while (ptr != NULL) {
        printf("%c", ptr->sym);
        ptr = ptr->next;
    }
    printf("\"\n");
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

int readline(node** list, const char* prompt) {
    printf("%s", prompt);
    char ch;

    while ((ch = getchar()) != '\n') {
        if (ch == EOF) {
            return EXIT_FAILURE;
        }
        push_back(list, ch);
    }
    push_back(list, '\0');

    printf("%s", "Original string: ");
    print_list(list);

    return EXIT_SUCCESS;
}

int is_cons(char c) {
    for(size_t i = 0; i < CONS_LEN; ++i) {
        if (cons[i] == c) return 1;
    }

    return 0;
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

void remove_spaces(node** list) {
    node* cur = *list;
    node* next;
    node *first, *last;
    int space_met = 0;

    while(cur != NULL) {
        last = cur->prev;
        if (cur->sym != ' ' && cur->sym != '\t') {
            cur = cur->next;
            space_met = 0;
        }
        else {
            if (!space_met) {
                space_met = 1;
                cur = cur->next;
            }
            else {
                next = cur->next;
                remove_node(list, cur);
                cur = next;
            }
        }
    }
    if (last != NULL) {
        if (last->sym == ' ' || last->sym == '\t') {
            remove_node(list, last);
        }
    }
    

    first = *list;
    if (first->sym == ' ' || first->sym == '\t') {
        remove_node(list, first);
    }
}

void remove_cons(node** list) {
    node* cur = *list;
    node* next;
    
    while(cur != NULL) {
        if (is_cons(cur->sym)) {
            next = cur->next;
            remove_node(list, cur);
            cur = next;
        }
        else {
            cur = cur->next;
        }
    }
}
