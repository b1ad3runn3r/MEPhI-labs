#pragma once

#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <time.h>

typedef struct client {
    char* name;
    char phone[17];
    time_t time;
} client;

int parse_line(char* line, client* cli);

int add_entry(client** clients, size_t* len, client cli);

int read_from_file(FILE* fp, client** clients, size_t* clients_len);

int write_to_file(FILE* fp, client** clients, size_t clients_len);

#endif // STRUCT_H
