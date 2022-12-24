#include "struct.h"
#include "utils.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int parse_line(char* line, client* cli) {
    char* tmp = NULL;

    /* Name */
    tmp = strtok(line, ";");
    cli->name = (char *)calloc(strlen(tmp) + 1, 1);
    if(cli->name == NULL) {
        return EXIT_FAILURE;
    }
    strcpy(cli->name, tmp);
    

    /* Phone number */
    tmp = strtok(NULL, ";");
    memset(cli->phone, 0, 17);
    strcpy(cli->phone, tmp);
    if (strlen(cli->phone) == 0) {
        return EXIT_FAILURE; //TODO: parse zero-len fields
    }

    /* Time */
    tmp = strtok(NULL, ";");
    cli->time = strtoll(tmp, NULL, 10);
    if (cli->time == 0) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int add_entry(client** clients, size_t* len, client cli) {
    client* new = NULL;
    new = realloc(*clients, sizeof(client) * (++(*len)));
    if (new == NULL) {
        free_arr(*clients, *len);
        *clients = NULL;
        return EXIT_FAILURE;
    }

    *clients = new;
    (*clients)[*len - 1] = cli;

    return EXIT_SUCCESS;
}

int read_from_file(FILE* fp, client** clients, size_t* clients_len) {
    client cli;

    size_t n_line = 0, len = 0;
    char* line = NULL;

    while (getline(&line, &len, fp) != -1) {
        ++n_line;
        len = strlen(line);
        if (len > 0) {
            if (line[len - 1] == '\n') {
                line[len - 1] = '\0';
            }
        }

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
            fprintf(stderr, "Unable to parse the line %zu!\n", n_line);
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
