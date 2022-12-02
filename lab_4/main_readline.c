#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include <readline/readline.h>

char* remove_spaces(char* input) {
    char* dst = calloc(0, sizeof(char));
    size_t dst_len = 0;
    int space_flag = 0;

    for(size_t i = 0; i < strlen(input); i++) {
        if (input[i] != ' ' && input[i] != '\t') {
            dst = realloc(dst, sizeof(char) * (++dst_len));
            dst[dst_len - 1] = input[i];
            space_flag = 0;
        }
        else {  
            if (!space_flag) {
                dst = realloc(dst, sizeof(char) * (++dst_len));
                dst[dst_len - 1] = ' ';
                space_flag = 1;
            }
        }
    }
    
    dst = realloc(dst, sizeof(char) * (dst_len + 1));
    dst[dst_len] = '\0';

    free(input);

    return dst;
}


char* swap(char* str) {
    if (strlen(str) < 2) {
        return str;
    }

    char tmp = 0;

    for(size_t i = 0; i < strlen(str) - 1; i += 2) {
        if (str[i] != ' ' && str[i + 1] != ' ') {
            tmp = str[i];
            str[i] = str[i + 1];
            str[i + 1] = tmp;
        } 
    }

    return str;
}


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
