#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

// 1 <= n <= 10^14, 2 <= m <= 10^3
// returns the array [F_i (mod m) for i in [0, 1, 2, ..., n]]
int fibo_10(ll n) {
    int *F = (int *) malloc(62 * sizeof(int));  // 62 is when F_n (mod 10) repeats
    F[0] = 0;
    F[1] = 1;
    int stop = 0, i = 2;
    while (!stop) {
        F[i] = (F[i-1] + F[i-2]) % 10;
        if (F[i] == 1 && F[i-1] == 0)
            stop = 1;
        i++;
    }
    // now i-2 is the length of the cycle. In our case, i-2 = 60
    int f = F[n % (i-2)];
    free(F);
    return f;
}

int sumFibo_10(ll n) {
    // we know that S[n] = F[n+2] - 1
    return (fibo_10(n+2) - 1 + 10) % 10;
}

int main() {
    ll n;
    scanf("%lld", &n);
    printf("%d\n", sumFibo_10(n));
    return 0;
}
