#pragma once

#ifndef SORT_H
#define SORT_H

#include "struct.h"

void swap(client* c1, client* c2);

int compare(client* c1, client* c2, int args);

void shell_sort(client* clients, size_t len, int (*compare)(client*, client*, int), int args);

int partition(client* clients, int low, int high, int (*compare)(client*, client*, int), int args);

void quick_sort(client* clients, int low, int high, int (*compare)(client*, client*, int), int args);

void process(client** clients, size_t len, int sort_al, int args);

#endif // SORT_H
