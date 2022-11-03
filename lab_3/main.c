#include "lib/menu.h"
#include "lib/utils.h"


int main() {
    printMenu();

    char state = 0;
    double* arr = NULL;
    double val = 0;
    int arr_len = 0, idx = 0;

    arr = initArray(arr, &arr_len);

    /* Implement a FSM (finite state machine) to check the input */


    while (state != QUIT) {
        state = getchar();

        switch (state) {
            case (PRINT) : {
                printArray(arr, arr_len);
                break;
            }

            case (ADD) : {
                printf("Now enter desired index and value: ");
                scanf("%d %lf", &idx, &val);

                if (idx < 0) {
                    printf("Index can't be negative!\n");
                    break;
                }

                arr = addElement(arr, &arr_len, val, idx);
                break;
            }

            case (POP) : {
                printf("Now enter desired index and value: ");
                scanf("%d %lf", &idx, &val);

                if (idx < 0) {
                    printf("Index can't be negative!\n");
                    break;
                }

                arr = popElement(arr, &arr_len, val, idx);
                break;
            }

            case (INDIVIDUAL) : {
                printf("to be done\n");
                break;
            }

            case (INIT) : {
                printf("to be done\n");
                break;
            }

            case (QUIT) : {
                printf("Exiting the program. Goodbye!\n");
                break;
            }

            default : {
                printf("Pizdets, wrong input!!1!. Please try again: ");
            }
        }

        __fpurge(stdin);
    }

    free(arr);
    return 0;
}