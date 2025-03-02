#include <stdio.h>
#include <stdlib.h>

// normal comparison between two integers
int cmp(const void *a, const void *b) {
    return *(int *)(a) - *(int *)(b);
}

int main() {
    int n;
    scanf("%d", &n);
    int *price, *clicks;
    price = (int *) malloc(n * sizeof(int));
    clicks = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &price[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &clicks[i]);
    qsort(price, n, sizeof(int), cmp);   // sorting the array of doubles in descending order
    qsort(clicks, n, sizeof(int), cmp);   // sorting the array of doubles in descending order
    int dotp = 0;
    for (int i = 0; i < n; i++)
        dotp += price[i] * clicks[i];
    printf("%d\n", dotp);
    free(clicks);
    free(price);
    return 0;
}
