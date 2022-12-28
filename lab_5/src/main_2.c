#include "lib/sort.h"
#include "lib/struct.h"
#include "lib/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <time.h>

const char abc[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,./<>?!@#$^&*()_+-={}[]|";
const char nums[] = "0123456789+ ";

client* gen_arr(int entries) {
    
    client tmp = {0};
    client* arr_res = NULL;
    size_t len = 0;
    char* res = NULL;

    for (int j = 0; j < entries; j++) {
        res = (char *)calloc(20 + 1 + 10 + 1 + 5 + 1, sizeof(char));
        for(int i = 0; i < 20; i++) {
            res[i] = abc[rand() % 86];
        }
        res[20] = ';';

        for(int i = 0; i < 10; ++i) {
            res[i + 21] = abc[rand() % 86];
        }
        res[31] = ';';

        for(int i = 0; i < 5; ++i) {
            res[i + 32] = nums[rand() % 12];
        }
        res[37] = '\0';

        parse_line(res, &tmp);
        add_entry(&arr_res, &len, tmp);
        free(res);
    }
    

    return arr_res;
}

long double timing(int arr_len, int arr_amt, int algo, int field) {
    long double res = 0.0f;
    clock_t start = 0, end = 0;
    client* clients = NULL;
    for (size_t i = 0; i < arr_amt; ++i) {
        clients = gen_arr(arr_len);
        start = clock();
        process(&clients, arr_len, algo, field);
        end = clock();
        free_arr(clients, arr_len);
        clients = NULL;
        res += (long double)(end - start) / CLOCKS_PER_SEC;
    }

    return res / arr_amt;
}

int main(int argc, char** argv) {
    srand(time(NULL));

    int opt, algo = 0, field = 0, opt_cnt = 0, ord = 0;
    int arr_len = 0, arr_amt = 0;


    while ((opt = getopt(argc, argv, "-:a:f:o:")) != -1) {
        switch(opt) {
            case 'a': // Sort algorithm
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

            case ':':
                fprintf(stderr, "Missing arg for %c\n", optopt);
                exit(EXIT_FAILURE);

            case 1:
                if (!opt_cnt) { // array len
                    arr_len = atoi(optarg);
                    if (arr_len < 0) {
                        fprintf(stderr, "%s\n", "Array length can't be negative!");
                        exit(EXIT_FAILURE);
                    }
                    ++opt_cnt;
                }
                else if (opt_cnt == 1) { // Amount of arrays
                    arr_amt = atoi(optarg);
                    if (arr_amt < 0) {
                        fprintf(stderr, "%s\n", "Array amount can't be negative!");
                        exit(EXIT_FAILURE);
                    }
                }
                break;
        }
    }


    
    long double res = timing(arr_len, arr_amt, algo, field);
    printf("%.20Lf\n", res);
    

    //free_arr(clients, len);
    return 0;
}