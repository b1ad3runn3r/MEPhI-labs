#include "string.h"

size_t my_strlen(char* str) {
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


char* swap(char* str) {
    if (my_strlen(str) < 2) {
        return str;
    }

    char tmp = 0;

    for(size_t i = 0; i < my_strlen(str) - 1; i += 2) {
        if (str[i] != ' ' && str[i + 1] != ' ') {
            tmp = str[i];
            str[i] = str[i + 1];
            str[i + 1] = tmp;
        } 
    }

    return str;
}


char* remove_spaces(char* input) {
    char* dst = calloc(0, sizeof(char));
    size_t dst_len = 0;
    int space_flag = 0;

    for(size_t i = 0; i < my_strlen(input); i++) {
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


char* my_readline(char* prompt) {
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
