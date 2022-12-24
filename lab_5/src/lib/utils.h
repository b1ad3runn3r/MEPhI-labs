#pragma once

#ifndef UTILS_H
#define UTILS_H

#include "struct.h"

void free_arr(client* arr, size_t len);

void print_table(client* table, size_t len);

int check_opts(char** args);

#endif //UTILS_H