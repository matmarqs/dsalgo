#include <stdio.h>

int fibo(int n) {
    if (n <= 1)
        return n;
    int f0 = 0, f1 = 1, f2;
    for (int i = 2; i <= n; i++) {
        f2 = f1 + f0;
        f0 = f1;
        f1 = f2;
    }
    return f2;
}

int main() {
    int a;
    scanf("%d", &a);
    printf("%d\n", fibo(a));
    return 0;
}
