#include <stdio.h>
#include <stdlib.h>

#define print_array(array, len, format) {   \
    printf("[ ");                           \
    for (ll i=0LL; i<len; i++)              \
    printf(format"%s", array[i],            \
    (i == (len)-1) ? " ]\n" : ", "); }

typedef long long ll;

// generates random long long value x, such that a <= x <= b
ll llrand(ll a, ll b) { // assumes RAND_MAX is (2^31 - 1)
    ll n64 = ((ll) rand() << 32) | (ll) rand();
    return a + n64 % (b - 1LL);
}

// 1 <= n <= 10^14, 2 <= m <= 10^3
// returns the array [F_i (mod m) for i in [0, 1, 2, ..., n]]
int fibo_m(ll n, int m) {
    int *F = (int *) malloc(10000 * sizeof(int));
    F[0] = 0;
    F[1] = 1;
    int stop = 0, i = 2;
    while (!stop) {
        F[i] = (F[i-1] + F[i-2]) % m;
        if (F[i] == 1 && F[i-1] == 0)
            stop = 1;
        i++;
    }
    // now i-2 is the length of the cycle
    int f = F[n % (i-2)];
    free(F);
    return f;
}

// this solution is slow. we have two consider the periodicity of F_n (mod m)
int fibo(ll n, ll m) {    // F_n (mod m)
    if (n <= 1LL)
        return n;
    int f0 = 0, f1 = 1, f2;
    for (int i = 2LL; i <= n; i++) {
        f2 = (f1 + f0) % m;
        f0 = f1 % m;
        f1 = f2 % m;
    }
    return f2;
}

void stress_test() {
    int run = 1;
    ll n; int m;
    srand(3);
    while(run) {
        n = llrand(1LL, 100000000LL);     // 1 <= n <= 10^8
        m = rand() % 999 + 2;     // 2 <= m <= 10^3
        int res1, res2;
        res1 = fibo_m(n, m);
        res2 = fibo(n, m);
        if (res1 != res2) {
            printf("Wrong: res1 = %d, res2 = %d, for n = %lld, m = %d\n", res1, res2, n, m);
            run = 0;
        }
        else {
            puts("OK");
        }
    }
}

int main() {
    //stress_test();
    ll n, m;
    scanf("%lld %lld", &n, &m);
    printf("%d\n", (int) fibo_m(n, m));
    return 0;
}
