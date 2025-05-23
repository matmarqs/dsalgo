#include <stdio.h>
#include <stdlib.h>

/* find index k, such that K[k] = q */
/* return -1 if not found */
int binary_search(int *K, int len, int q) {
    int left = 0;
    int right = len-1;

    while (left <= right) {
        int mid = (left + right)/2;
        if (K[mid] == q) {
            return mid;
        }
        else if (K[mid] < q) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

void sorted_array_multiple_search() {
    int n;
    scanf("%d", &n);

    int *K = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &K[i]);
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int q;
        scanf("%d", &q);
        printf("%d\n", binary_search(K, n, q));
    }

    free(K);
}

int main() {
    int K[] = {1, 3, 7, 8, 9, 12, 15};
    int q = 9;
    printf("%d\n", binary_search(K, 7, q));
}
