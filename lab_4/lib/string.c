#include "string.h"

size_t my_strlen(char* str) {
    const char* char_ptr;

    for (char_ptr = str; (size_t)char_ptr != 0; ++char_ptr) {
        if (*char_ptr == '\0'){
            return char_ptr - str;
        }
    }

    return 0; //TODO: think on error condition
}
