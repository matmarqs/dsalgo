#include "header.h"
#include <string.h>

// comparison: concatenation of two integers. descending order
int cmp(const void *a, const void *b) {
    int ia = *(int *)(a);
    int ib = *(int *)(b);
    char res_a[9], res_b[9];
    sprintf(res_a, "%d%d", ia, ib);
    sprintf(res_b, "%d%d", ib, ia);
    return atoi(res_b) - atoi(res_a);
}

int main() {
    int n;
    scanf("%d", &n);
    int *integers = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &integers[i]);
    qsort(integers, n, sizeof(int), cmp);
    char result[401] = "\0", aux[5];
    for (int i = 0; i < n; i++) {
        sprintf(aux, "%d", integers[i]);
        strcat(result, aux);
    }
    printf("%s\n", result);
    return 0;
}
