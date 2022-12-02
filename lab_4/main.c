#include <time.h>

#include "lib/string.h"

int main() {
    char* input = NULL;
    clock_t timer;
    
    while(1) {
        timer = clock();
        input = my_readline("Enter a line: ");

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
