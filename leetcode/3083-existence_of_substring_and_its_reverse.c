#include <stdbool.h>

/***********************/

/* this solution could be improved by a HashMap in the function isSubstring */

#include <stdlib.h>
#include <string.h>

bool isSubstring(char *s, int len_s, char *sub, int len_sub) {
    for (int i = 0; i < len_s - len_sub + 1; i++) {
        bool substring = true;
        for (int j = 0; j < len_sub; j++) {
            if (sub[j] != s[i+j]) {
                substring = false;
            }
        }
        if (substring)
            return true;
    }
    return false;
}

bool isSubstringPresent(char* s) {
    int len_s = strlen(s);
    char *rev = (char *) malloc(sizeof(char) * (len_s+1));
    for (int i = len_s-1; i >= 0; i--) {
        rev[i] = s[len_s-1-i];
    }
    rev[len_s] = '\0';

    int result = false;
    for (int i = 0; i < len_s - 1; i++) {
        if (isSubstring(rev, len_s, s+i, 2)) {
            result = true;
            break;
        }
    }

    free(rev);
    return result;
}
