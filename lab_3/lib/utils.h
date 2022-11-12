#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

void       printArray(double*, int);

double     *addElement(double*, int*, double, int);

double     *popElement(double*, int*, int);

int        splitAndCheck(double);

double     *individualTask(double*, int*);

double     *initArray(double*, int*);

char       toLower(char);

#endif
