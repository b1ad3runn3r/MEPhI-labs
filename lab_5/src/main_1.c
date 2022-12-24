#include "lib/sort.h"
#include "lib/struct.h"
#include "lib/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

int main(int argc, char** argv) {
    client* clients = NULL;
    size_t len = 0;
    int opt, algo = 0, field = 0, opt_cnt, ord = 0;

    FILE* in_fp;
    FILE* out_fp;

    while ((opt = getopt(argc, argv, "-:a:f:o:")) != -1) {
        switch(opt) {
            case 'a': // Sort algorithm
                printf("Option a has arg: %s\n", optarg);
                if (!strcmp(optarg, "quick_l")) {
                    algo = 0;
                }
                else if (!strcmp(optarg, "quick_s")) {
                    algo = 1;
                }
                else if (!strcmp(optarg, "shell")) {
                    algo = 2;
                }
                else {
                    fprintf(stderr, "Wrong sorting algorithm %s\n", optarg);
                    exit(EXIT_FAILURE);
                }

                break;

            case 'f': // Field (Name, Phone or time)
                printf("Option f has arg: %s\n", optarg);
                if (!strcmp(optarg, "name")) {
                    field = 1;
                }
                else if (!strcmp(optarg, "phone")) {
                    field = 2;
                }
                else if (!strcmp(optarg, "time")) {
                    field = 3;
                }
                else {
                    fprintf(stderr, "Wrong sorting field %s\n", optarg);
                    exit(EXIT_FAILURE);
                }
                break;

            case 'o': // Order (Ascend or descend)
                printf("Option o has arg: %s\n", optarg);
                if (!strcmp(optarg, "asc")) {
                    field *= 1;
                }
                else if (!strcmp(optarg, "desc")) {
                    field *= -1;
                }
                else {
                    fprintf(stderr, "Wrong order field %s\n", optarg);
                    exit(EXIT_FAILURE);
                }
                break;

            case '?':
                fprintf(stderr, "Unknown option: %c\n", optopt);
                exit(EXIT_FAILURE);
                //break;

            case ':':
                fprintf(stderr, "Missing arg for %c\n", optopt);
                exit(EXIT_FAILURE);
                //break;

            case 1:
                printf("Non-option arg: %s\n", optarg);
                if (!opt_cnt) {
                    in_fp = fopen(optarg, "rb");
                    if (in_fp == NULL) {
                        fprintf(stderr, "Error opening file %s: %s\n", optarg);
                        exit(EXIT_FAILURE);
                    }
                    ++opt_cnt;
                }
                else if (opt_cnt == 1) {
                    out_fp = fopen(optarg, "wb");
                    if (out_fp == NULL) {
                        fprintf(stderr, "Error opening file %s: %s\n", optarg);
                        exit(EXIT_FAILURE);
                    }
                }
                break;
        }
    }

    
    read_from_file(in_fp, &clients, &len);
    process(&clients, len, algo, field);
    print_table(clients, len);
    write_to_file(out_fp, &clients, len);


    free_arr(clients, len);
    fclose(in_fp);
    fclose(out_fp);
    
    return 0;
}