#include "lib/sort.h"
#include "lib/struct.h"
#include "lib/utils.h"
#include <stdio.h>

int main(int argc, char** argv) {
    client* clients = NULL;
    size_t len = 0;

    FILE* in_fp = fopen("/home/b1ad3runn3r/MEPhI-labs/lab_5/db.txt", "rb");
    read_from_file(in_fp, &clients, &len);
    print_table(clients, len);

    free_arr(clients, len);
    return 0;
}