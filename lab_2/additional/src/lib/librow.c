#include "librow.h"
#include <math.h>
#include <stdio.h>

ldouble rowNMembers(ldouble a, int n, int num_mem){
    long double cur = 1, tmp = 0;
    
    for (int i = 0; i < num_mem; i++){
        tmp = pow(cur, n);
        cur = (cur / (n * n)) * ((n * n - 1) + 0.5 * (n + 1) * (a / tmp) - 0.5 * (n - 1) * (tmp / a));
    }

    return cur;
}

ldouble rowEpsilon(ldouble a, int n, ldouble eps, int* cnt){
    long double cur = 1.0, prev = 1.0, tmp = 0;

    do{
        prev = cur;
        tmp = pow(prev, n);
        cur = (prev / (n * n)) * ((n * n - 1) + 0.5 * (n + 1) * (a / tmp) - 0.5 * (n - 1) * (tmp / a));
        *cnt += 1;
    } while (fabsl(cur - prev) >= eps);

    return cur;
}

void __attribute__ ((constructor)) initLibrary(void) {
 //
 // Function that is called when the library is loaded
 //
    printf("Library is initialized\n"); 
}
void __attribute__ ((destructor)) cleanUpLibrary(void) {
 //
 // Function that is called when the library is »closed«.
 //
    printf("Library is exited\n"); 
}
