#include <stdio.h>
#include <stdlib.h>

int *sum_array(int *array, int N) {
    int *sums = malloc(N * sizeof(int));
    sums[0] = array[0];
    for (int i = 1; i < N; i++)
        sums[i] = sums[i-1] + array[i];
    return sums;
}

int range(int l, int r, int *sums) {
    return sums[r-1] - sums[l-1];
}

int main() {
    int array[] = {2, -1, 7, 2, -3, -2, 4};
    int N = 7;
    int *sums = sum_array(array, N);
    printf("%d\n", range(1, 4, sums));
    printf("%d\n", range(2, 6, sums));
    free(sums);
    return 0;
}
