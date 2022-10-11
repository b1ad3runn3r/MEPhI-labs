#include <stdio.h>
#include <math.h>
#include "lib/librow.h"

int main(){
    int cnt = 0;

    ldouble res1 = rowNMembers(2, 2, 10);
    ldouble res2 = rowEpsilon(2, 2, 1e-10, &cnt);
    
    int precision = round(fabs(log10(1e-10)));


    printf("1: %.20Lf\n", res1);
    printf("2: %.*Lf\n", precision, res2);
    printf("2 took %d iters", cnt);

    return 0;
}
