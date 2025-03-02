#include <stdio.h>

int josephus(int n, int k) {
    if (n == 1)     // josephus(1, k) = 0, obviously
        return 0;
    return (josephus(n-1, k) + k) % n;  // n -> (n-1) and we get a shift of `k (mod n)`
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("josephus(%d, %d) = %d\n", n, k, josephus(n, k));
    return 0;
}
