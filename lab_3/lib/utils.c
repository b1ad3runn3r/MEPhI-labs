#include "utils.h"


void printArray(double* arr, int arr_len) {
    printf("{");

    for (int i = 0; i < arr_len - 1; ++i) {
        printf("%lf, ", arr[i]);
    }
    printf("%lf}\n", arr[arr_len - 1]);
}


double *addElement(double* arr, int* arr_len, double val, int idx) {
    arr = (double *) realloc(arr, sizeof(double) * (*arr_len + 1));

    if (idx >= *arr_len) {
        arr[*arr_len] = val;
    }
    else {
        memmove(&arr[idx + 1], &arr[idx], sizeof(double) * (*arr_len - idx));
        arr[idx] = val;
    }

    *arr_len += 1;
    return arr;
}


double* popElement(double* arr, int* arr_len, int idx) {
    if (idx < *arr_len - 1) {
        memmove(&arr[idx], &arr[idx + 1], sizeof(double) * (*arr_len - idx - 1));
    } 

    arr = realloc(arr, sizeof(double) * (*arr_len - 1));

    *arr_len -= 1;
    return arr;
}


int splitAndCheck(double num) {
    /*
    The condition here is to check, if the fractional part
    is equal to the integer part, divided to be fully fractional...
    */

    num = fabs(num);

    int integ = 0, frac = 0;
    char tmp[128];

    sprintf(tmp, "%lf", num);
    sscanf(tmp, "%d.%d", &integ, &frac);

    while(!(frac % 10)) {
        frac /= 10;
    }
    
    return (frac > integ);
}


double* individualTask(double* arr, int* arr_len) {
    int* bad_idx = calloc(1, sizeof(int));
    int bad_idx_len = 1;
    int offset = 0;

    for (int i = 0; i < *arr_len; ++i){
        if (splitAndCheck(arr[i])) {
            bad_idx[bad_idx_len - 1] = i;
            bad_idx = (int *) realloc(bad_idx, sizeof(int) * (*arr_len + 1));
            bad_idx_len += 1;
        }
    }

    bad_idx_len -= 1;

    for (int i = 0; i < bad_idx_len; i++) {
        arr = popElement(arr, arr_len, bad_idx[i - offset]);
        offset += 1;
    }

    free(bad_idx);

    return arr;
}


double* initArray(double* arr, int* arr_len) {
    arr = (double *) calloc(*arr_len, sizeof(double));
    return arr;
}


char toLower(char ch) {
    return (ch >= 'A' && ch <= 'Z') ? (ch | 0x60) : (ch);
}
