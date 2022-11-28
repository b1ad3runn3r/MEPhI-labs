#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <stdlib.h>


char* remove_spaces(char* input) {
    char* dst = calloc(0, sizeof(int));
    int dst_len = 0;
    int space_flag = 0;

    for(size_t i = 0; i < strlen(input); i++) {
        if (input[i] != ' ' && input[i] != '\t') {
            dst = realloc(dst, sizeof(int) * (++dst_len));
            dst[dst_len - 1] = input[i];
            space_flag = 0;
        }
        else {  
            if (!space_flag) {
                dst = realloc(dst, sizeof(int) * (++dst_len));
                dst[dst_len - 1] = ' ';
                space_flag = 1;
            }
        }
    }

    dst[dst_len] = '\0';

    return dst;
}


void swap(char** str) {
    if (strlen(*str) < 2) {
        return;
    }

    char tmp = 0;

    for(size_t i = 0; i < strlen(*str); i += 2) {
        if (*(*str + i) != ' ' && *(*str + i + 1) != ' ') {
            tmp = *(*str + i);
            *(*str + i) = *(*str + i + 1);
            *(*str + i + 1) = tmp;
        } 
    }
}


int main() {
    char* input = NULL;

    while(1) {
        input = readline("Enter a line: ");
        
        if (!input) {
            break;
        }

        input = remove_spaces(input);
        swap(&input);
        printf("%s\n", input);
        
        free(input);
    }

    return 0;
}
