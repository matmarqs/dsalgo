#include <stdio.h>
#include <stdlib.h>

void print_array(int *a, int n){
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int greater_or_equal_to_kth_place(int *a, int n, int k) {
    if (n == 0) {
        return 0;
    }
    else {
        int kth_place_finisher_score = a[k-1];
        int i = k-1;
        while (i < n && a[i] == kth_place_finisher_score) {
            i++;
        }
        return i;
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int *a = malloc(sizeof(int) * n);
    int aux;
    for (int i = 0; i < n; i++) {
        scanf("%d", &aux);
        a[i] = aux;
    }
    int num_participants = greater_or_equal_to_kth_place(a, n, k);
    int count = 0;
    for (int i = 0; i < num_participants; i++) {
        if (a[i] > 0) {
            count++;
        }
        else {
            break;
        }
    }
    printf("%d\n", count);
    free(a);
    return 0;
}
