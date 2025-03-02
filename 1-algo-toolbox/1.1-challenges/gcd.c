#include <stdio.h>

typedef long long ll;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(int a, int b) {
    return ((ll) a / gcd(a, b)) * b;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%lld\n", lcm(a, b));
    return 0;
}
