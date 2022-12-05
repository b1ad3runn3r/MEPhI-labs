#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib/common/common.h"
#include <readline/readline.h>

int main() {
    char* input = NULL;
    clock_t timer;

    while(1) {
        timer = clock();
        input = readline("Enter a line: ");
        
        if (!input) {
            break;
        }

        input = remove_spaces(input);
        input = swap(input);
        printf("\"%s\"\n", input);

        timer = clock() - timer;
        double time_taken = (double)timer / CLOCKS_PER_SEC;
        printf("Took %lf seconds!\n", time_taken);
        
        free(input);
    }

    return 0;
}
