#include <stdio.h>
#include <math.h>

long double rowEpsilon(long double a, int n, long double eps, int* cnt){
    long double cur = 1.0, prev = 1.0, tmp = 0;
    do{
        prev = cur;
        tmp = pow(prev, n);
        cur = (prev / (n * n)) * ((n * n - 1) + 0.5 * (n + 1) * (a / tmp) - 0.5 * (n - 1) * (tmp / a));
        *cnt += 1;
    } while (fabsl(cur - prev) >= eps);

    return cur;
}

int main(){
    printf("/* Please enter a, n, eps */!\n");

    long double a = 0, eps = 0;
    int n = 0;

    if (!(scanf("%Lf", &a) && 
          scanf("%d", &n) &&
          scanf("%Lf", &eps) )){ /* input check */

        printf("Wrong input!\n");
        return -1;
    }

    int precision = round(fabs(log10(eps))), cnt = 0;
    
    long double res1 = pow(a, 1.0/n);
    long double res2 = rowEpsilon(a, n, eps, &cnt);

    printf("Lib: %.*Lf\n", precision, res1);
    printf("Self: %.*Lf\n",precision, res2);
    printf("Diff: %.*Lf\n", precision, fabsl(res1 - res2));
    printf("Took %d iterations", cnt);

    return 0;
}
