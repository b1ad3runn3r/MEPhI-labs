#include <stdio.h>
#include <math.h>

long double rowNMembers(long double a, int n, int num_members){
    if (a == 0){
        return 0.0;
    }

    long double cur = 1, tmp = 0;
    
    for (int i = 0; i < num_members; i++){
        tmp = pow(cur, n);
        cur = (cur / (n * n)) * ((n * n - 1) + 0.5 * (n + 1) * (a / tmp) - 0.5 * (n - 1) * (tmp / a));
    }

    return cur;
}

int main(){ 
    printf("/* Please enter a, n, num_mem */!\n");

    long double a = 0;
    int n = 0, num_mem = 0;

    if (!(scanf("%Lf", &a) && 
          scanf("%d", &n) &&
          scanf("%d", &num_mem) )){ /* input check */

        printf("Wrong input!\n");
        return -1;
    }

    if (a < 0 || num_mem < 0 || n <= 0){
        printf("a, num_mem and n can't be negative!\n");
        return -1;
    }
    
    long double res1 = pow(a, 1.0/n);
    long double res2 = rowNMembers(a, n, num_mem);

    printf("Lib: %.20Lf\n", res1);
    printf("Self: %.20Lf\n", res2);
    printf("Diff: abs lib - row: %.20Lf\n", fabsl(res1 - res2));

    return 0;
}
