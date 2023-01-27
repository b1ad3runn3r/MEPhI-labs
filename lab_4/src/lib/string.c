#include "string.h"
#include <stdlib.h>
#include <stdio.h>

size_t my_strlen(const char* str) {
    const char* char_ptr;

    for (char_ptr = str; (size_t)char_ptr != 0; ++char_ptr) {
        if (*char_ptr == '\0'){
            return char_ptr - str;
        }
    }

    return 0;
}


void my_memcpy(char* dest, char* src, size_t n) {
    char* cpy_dest = (char *) dest;
    char* cpy_src = (char *) src;

    for(size_t i = 0; i < n; ++i) {
        cpy_dest[i] = cpy_src[i];
    }
}


char* my_readline(const char* prompt) {
    printf("%s", prompt);

    char buf[CHUNK + 1] = {0};
    char* result = NULL;

    size_t len = 0;
    int scan_res = 0;
    do {
        scan_res = scanf("%100[^\n]", buf);
        if (scan_res < 0) {
            if (!result) {
                return NULL;
            }
        }
        else if (scan_res > 0) {
            size_t chunk_len = my_strlen(buf);
            size_t str_len = len + chunk_len;

            result = realloc(result, str_len + 1);
            my_memcpy(result + len, buf, chunk_len);

            len = str_len;
        }
        else {
            scanf("%*c");
        }
    } while (scan_res > 0);

    if (len > 0) {
        result[len] = '\0';
    }
    else {
        result = calloc(1, sizeof(char));
    }

    return result;
}
