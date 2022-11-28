#include "lib/string.h"

int main() {
    char* input = NULL;
    
    while(1) {
        input = my_readline("Enter a line: ");

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
