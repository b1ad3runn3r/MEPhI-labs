#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void free_arr(client* arr, size_t len) {
    for(size_t i = 0; i < len; ++i) {
        free(arr[i].name);
    }
    free(arr);
}

void print_table(client* table, size_t len) {
    printf("%-30s %-16s %-20s\n", "Name", "Phone number", "Last call");
    for (size_t i = 0; i < len; ++i) {
        printf("%-30s %-16s %-20ld\n", table[i].name, table[i].phone, table[i].time);
    }
}
