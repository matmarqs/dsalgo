#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

#define MAX(a, b)   (((a) > (b)) ? (a) : (b))
#define MIN(a, b)   (((a) > (b)) ? (b) : (a))
#define PRINT_ARRAY(array, len, format) {   \
    printf("[ ");                           \
    for (ll i=0LL; i<len; i++)              \
    printf(format"%s", array[i],            \
    (i == (len)-1) ? " ]\n" : ", "); }
