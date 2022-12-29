#include "struct.h"
#include "utils.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int parse_line(char* line, client* cli) {
    char* tmp = NULL;
    int cnt = 0;
    for(int i = 0; i < strlen(line); i++) {
        if (line[i] == ';') {
            cnt += 1;
        }
    }
    for(int i = 0; i < strlen(line) - 1; i++) {
        if (line[i] == ';' && line[i + 1] == ';') {
            return EXIT_FAILURE; //костыли, люблю запах костылей по утрам
        }
    }

    if (cnt != 2) {
        return EXIT_FAILURE;
    }

    /* Name */
    tmp = strtok(line, ";");

    if (tmp == NULL || strlen(tmp) == 0) {
        return EXIT_FAILURE;
    }

    cli->name = strdup(tmp);
    if(cli->name == NULL) {
        return EXIT_FAILURE;
    }

    /* Phone number */
    tmp = strtok(NULL, ";");
    if (tmp == NULL) {
        return EXIT_FAILURE;
    }

    if(strlen(tmp) > 16 || strlen(tmp) == 0) {
        return EXIT_FAILURE;
    }

    memset(cli->phone, 0, 17);
    strcpy(cli->phone, tmp);

    /* Time */
    tmp = strtok(NULL, ";");
    if (tmp == NULL) {
        return EXIT_FAILURE;
    }

    for(int i = 0; i < strlen(tmp); i++) {
        if (tmp[i] < '0' || tmp[i] > '9') {
            return EXIT_FAILURE;
        }
    }

    cli->time = strtoll(tmp, NULL, 10);

    return EXIT_SUCCESS;
}

int add_entry(client** clients, size_t* len, client cli) {
    *clients = realloc(*clients, sizeof(client) * (++(*len)));
    if (*clients == NULL) {
        free_arr(*clients, *len);
        *clients = NULL;
        return EXIT_FAILURE;
    }

    (*clients)[*len - 1] = cli;

    return EXIT_SUCCESS;
}

int read_from_file(FILE* fp, client** clients, size_t* clients_len) {
    client cli;

    size_t line_num = 0, s_len = 0;
    char* line = NULL;

    while (getline(&line, &s_len, fp) != -1) {
        
        s_len = strlen(line);
        if (s_len > 0) {
            if (line[s_len - 1] == '\n') {
                line[s_len - 1] = '\0';
            }
        }

        ++line_num;
        if(!parse_line(line, &cli)) {
            if (add_entry(clients, clients_len, cli)) {
                free(cli.name);
                if (*clients != NULL) {
                    free_arr(*clients, *clients_len);
                }
                free(line);
                return EXIT_FAILURE;
            }
        }
        else {
            fprintf(stderr, "Can't parse line %zu!\n", n_line);
        }
    }

    free(line);
    return EXIT_SUCCESS;
}

int write_to_file(FILE* fp, client** clients, size_t clients_len) {
    char buf[50] = ""; // For time due to its time_t type
    for (size_t i = 0; i < clients_len; ++i) {
        fputs((*clients)[i].name, fp);
        fputs(";", fp);

        fputs((*clients)[i].phone, fp);
        fputs(";", fp);

        snprintf(buf, sizeof(buf), "%zu", (*clients)[i].time);
        fputs(buf, fp);
        fputs("\n", fp);
    }

    return EXIT_SUCCESS;
}
