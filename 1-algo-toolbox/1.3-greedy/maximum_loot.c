#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

#define ARRAYSIZE(a)    (sizeof(a) / sizeof(a[0]))
#define MAX(a, b)   (((a) > (b)) ? (a) : (b))
#define MIN(a, b)   (((a) > (b)) ? (b) : (a))
#define PRINT_ARRAY(array, len, format) {   \
    printf("[ ");                           \
    for (ll i=0LL; i<len; i++)              \
    printf(format"%s", array[i],            \
    (i == (len)-1) ? " ]\n" : ", "); }

typedef struct {
    int cost;
    int weight;
    double x;   /* cost / weight */
} compound;

int sign(double x) {
    if (x > 0)
        return 1;
    if (x < 0)
        return -1;
    return 0;
}

// compare two compounds, based on c[i] / w[i] in descending order
int cmp_descending(const void *a, const void *b) {
    compound *ca = (compound *) a;
    compound *cb = (compound *) b;
    return sign((double)(cb->x) - (double)(ca->x));
}

// assumes the array `x` of (cost/weight) is already sorted in descending order
double maximum_loot(int W, compound *c, int n) {
    int take;
    double loot = 0;
    int i = 0;
    while (i < n && W > 0) {
        take = MIN(c[i].weight, W);
        loot += c[i].x * take;
        W -= take;
        i++;
    }
    return loot;
}

int main() {
    int n, W;
    scanf("%d %d", &n, &W);
    compound *c = malloc(n * sizeof(compound));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &(c[i].cost), &(c[i].weight));
        c[i].x = c[i].cost / (double) c[i].weight;
    }
    qsort(c, n, sizeof(compound), cmp_descending);   // sorting the array of doubles in descending order
    printf("%lf\n", maximum_loot(W, c, n));
    free(c);
    return 0;
}
