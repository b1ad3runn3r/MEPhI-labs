#define _GNU_SOURCE

#include "sort.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void swap(client* c1, client* c2) {
    client tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
}

int compare(client* c1, client* c2, int args) {
    if (args > 0) {
        if (args == 1) {
            return strcmp(c1->name, c2->name);
        }
        else if (args == 2) {
            return strcmp(c1->phone, c2->phone);
        }
        else {
            return c1->time - c2->time;
        }
    }
    else {
        if (args == -1) {
            return strcmp(c2->name, c1->name);
        }
        else if (args == -2) {
            return strcmp(c2->phone, c1->phone);
        }
        else {
            return c2->time - c1->time; // TODO: fix size_t from int function return
        }
    }
}

int partition(client* clients, int low, int high, int (*compare)(client*, client*, int), int args) {
    client* pivot = clients + high;
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if ((*compare)(clients + j, pivot, args) <= 0) {
            i++;
            swap(clients + i, clients + j);
        }
    }
    swap(clients + i + 1, clients + high);
    return (i + 1);
}

void quick_sort(client* clients, int low, int high, int (*compare)(client*, client*, int), int args) {
    if (low < high) {
        int pi = partition(clients, low, high, compare, args);

        quick_sort(clients, low, pi - 1, compare, args);
        quick_sort(clients, pi + 1, high, compare, args);
    }
}

void shell_sort(client* clients, size_t len, int (*compare)(client*, client*, int), int args) {
    for(int i = len / 2; i > 0; i /= 2) {
        for (int j = i; j < len; ++j) {
            for (int k = j - i; k >= 0; k -= i) {
                if ((*compare)(clients + k + 1, clients + k, args) >= 0) {
                    break;
                }
                else {
                    swap(clients + k, clients + k + 1);
                }
            }
        }
    }
}

void process(client** clients, size_t len, int sort_al, int args) {
    if (sort_al == 0) {
        qsort_r(*clients, len, sizeof(client), &compare, args);
    }
    else if (sort_al == 1) {
        quick_sort(*clients, 0, len - 1, &compare, args);
    }
    else {
        shell_sort(*clients, len, &compare, args);
    }
}
