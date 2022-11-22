#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <stdlib.h>

void swap(char** str) { //TODO: check for 0 len string
    char tmp = 0;
    printf("%lu\n", strlen(*str));

    for(size_t i = 0; i < strlen(*str) - 1; i += 2) {
        tmp = *(*str + i);
        *(*str + i) = *(*str + i + 1);
        *(*str + i + 1) = tmp;
    }
}

int main() {
    char* input;

    while(1) {
        input = readline("Enter a line: ");
        
        if (!input) {
            break;
        }

        swap(&input);
        printf("%s\n", input);
        
        free(input);
    }

    return 0;
}
