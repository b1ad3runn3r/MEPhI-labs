#include <stdio.h>
#include "lib/lib.h"


int main() {
    node* list = NULL;
    int state = 0;

    while(1) {
        state = readline(&list, "> ");
        if (state) {
            break;
        }
        
        remove_spaces(&list);
        remove_cons(&list);

        printf("%s", "Result string: ");
        print_list(&list);

        free_list(&list);
    }

    return 0;
}
