#include <stdbool.h>

/******************************************************/

//#include <stdlib.h>
//
//typedef struct {
//    char c;
//    int count;
//} CharCount;
//
//typedef struct {
//    CharCount *ch;
//} Chars;
//
//Chars *chars_create(int initial_size) {
//    Chars *chars = (Chars *) malloc(sizeof(Chars));
//    chars->ch = (CharCount *) malloc(sizeof(CharCount) * initial_size);
//    return chars;
//}
//
//void chars_free(Chars *chars) {
//    free(chars->ch);
//    free(chars);
//}
//
//void chars_push(Chars *chars, char c) {
//}

bool isIsomorphic(char* s, char* t) {
    int count_s[256] = {0};
    int count_t[256] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        count_s[s[i]]++;
        count_t[t[i]]++;
    }

    int size_s = 0;
}
