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

void qsort_s(client* clients, int (*compare)(client*, client*, int), int args, int low, int high) {
    int i, j, pivot, temp;
    if(low < high){
        pivot = low;
        i = low;
        j = high;
        while(i<j){
            while((*compare)(clients + i, clients + pivot, args) <= 0 && i < high)
                i++;
            while((*compare)(clients + j, clients + pivot, args) > 0)
                j--;
            if ( i < j ){
                swap(clients + i, clients + j);
            }
        }
        swap(clients + pivot, clients + j);

        qsort_s(clients, &compare, args, low, j - 1);
        qsort_s(clients, &compare, args, j + 1, high);
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

/*
void odd_even_sort(subscriber *arr, size_t len, int (*func)(subscriber*, subscriber*, char**), char **args){
    bool status = false;
    while (!status){
        status = true;
        for (int i = 0; i < len - 1; i += 2){
            if((*func)(arr + i, arr + i + 1, args) > 0){
                swap(arr + i, arr + i + 1);
                status = false;
            }
        }
        for (int i = 1; i < len - 1; i += 2){
            if((*func)(arr + i, arr + i + 1, args) > 0){
                swap(arr + i, arr + i + 1);
                status = false;
            }
        }
    }
}
*/
void process(client** clients, size_t len, int sort_al, int args) {
    if (sort_al == 0) {
        qsort_r(*clients, len, sizeof(client), &compare, args);
    }
    else if (sort_al == 1) {
        qsort_s(*clients, &compare, args, 0, (int)(len - 1));
    }
    else {
        shell_sort(*clients, len, &compare, args);
    }
}
