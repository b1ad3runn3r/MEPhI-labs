#include "common.h"
#include <stdlib.h>

#ifdef READLINE
    #include <string.h>
    #define __strlen strlen
#else
    #include "string.h"
    #define __strlen my_strlen
#endif

char* swap(char* str) {
    if (__strlen(str) < 2) {
        return str;
    }

    char tmp = 0;

    for(size_t i = 0; i < __strlen(str) - 1; i += 2) {
        if (str[i] != ' ' && str[i + 1] != ' ') {
            tmp = str[i];
            str[i] = str[i + 1];
            str[i + 1] = tmp;
        } 
    }

    return str;
}


char* remove_spaces(char* str) {
    char* dst = NULL;
    size_t dst_len = 0;
    int space_flag = 0;

    for(size_t i = 0; i < __strlen(str); i++) {
        if (str[i] != ' ' && str[i] != '\t') {
            dst = realloc(dst, sizeof(char) * (++dst_len));
            dst[dst_len - 1] = str[i];
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
    
    dst = realloc(dst, sizeof(char) * (++dst_len));
    dst[dst_len - 1] = '\0';

    free(str);
    return dst;
}
