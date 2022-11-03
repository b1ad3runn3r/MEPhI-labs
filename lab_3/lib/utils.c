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

    if (idx > *arr_len) {
        arr[*arr_len] = val;
    }
    /*
    else if (idx == -1) {
        arr[*arr_len] //TODO: Do something about "appending" a nelement into array
    }
    */
    else {
        memmove(&arr[idx + 1], &arr[idx], sizeof(double) * (*arr_len - idx));
        arr[idx] = val;
    }

    *arr_len += 1;
    return arr;
}


double* popElement(double* arr, int* arr_len, double val, int idx) {
    memmove(&arr[idx], &arr[idx + 1], sizeof(double) * (*arr_len - idx - 1));

    arr[idx] = val;

    arr = realloc(arr, sizeof(double) * (*arr_len - 1));

    *arr_len -= 1;
    return arr;
}


void splitAndCheck(double* num, int* state) {
    /*
    The condition here is to check, if the fractional part
    is equal to the integer part, divided to be fully fractional...
    */

    double integ = 0, frac = 0;

    frac = modf(*num, &integ);

    integ /= pow(10, (floor(log10(integ))) + 1);

    *state = (frac > integ) ? 1 : 0;
}


double* initArray(double* arr, int* arr_len) {
    arr = (double *) calloc(*arr_len, sizeof(double));
    return arr;
}


char toLower(char ch) {
    return (ch >= 'A' && ch <= 'Z') ? (ch | 0x60) : (ch);
}
