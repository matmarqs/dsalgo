#include <stdio.h>
#include <stdlib.h>

// `n` is the length of the array `stop`, which has an additional stop for `d`
int minimum_refills(int m, int n, int *stop) {
    int current = 0, reffils = 0, reach_next = 0;
    for (int i = 0; i < n; i++) {
        if (stop[i] <= current + m) {
            reach_next = 1;
            continue;
        }
        else if (!reach_next)
            return -1;
        current = stop[i-1];
        reffils++;
        reach_next = 0;
    }
    return reffils;
}

int main() {
    int d, m, n;
    scanf("%d", &d);
    scanf("%d", &m);
    scanf("%d", &n);
    int *stop = malloc((n+1) * sizeof(int));    // additional stop for `d`
    for (int i = 0; i < n; i++) {
        scanf("%d", &stop[i]);
    }
    stop[n] = d;    // last stop is `d`
    printf("%d\n", minimum_refills(m, n+1, stop));
    free(stop);
    return 0;
}
