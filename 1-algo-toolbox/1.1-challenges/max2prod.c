#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

#define print_array(array, len, format) {   \
    printf("[ ");                           \
    for (ll i=0LL; i<len; i++)              \
    printf(format"%s", array[i],            \
    (i == (len)-1) ? " ]\n" : ", "); }

// generates random long long value x, such that a <= x <= b
ll llrand(ll a, ll b) { // assumes RAND_MAX is (2^31 - 1)
    ll n64 = ((ll) rand() << 32) | (ll) rand();
    return a + n64 % (b - 1LL);
}

// n = len(L); complexity O(n)
ll max2prod(ll n, ll *L) {
    ll max1 = 0LL, max2 = 0LL;  // max1 >= max2
    for (ll i = 0LL; i < n; i++) {
        if (L[i] > max1) {
            max2 = max1;
            max1 = L[i];
        }
        else if (L[i] > max2)
            max2 = L[i];
    }
    return max1 * max2;
}

// complexity O(n^2)
ll max2prod_slow(ll n, ll *L) {
    ll prod, maxprod = 0LL;
    for (ll i = 0LL; i < n; i++)
        for (ll j = i+1LL; j < n; j++) {
            prod = L[i] * L[j];
            if (prod > maxprod)
                maxprod = prod;
        }
    return maxprod;
}

// check if the two algorithms differ
void stress_test(int argc, char *argv[]) {
    ll n, *L;
    if (argc > 1)
        srand(atoi(argv[1]));   // set seed, 1st CLI arguments
    ll res1, res2;
    int run = 1;
    while(run) {
        n = llrand(2LL, 200000LL);      // random value between 2 and 2*10^5 included
        L = malloc(n * sizeof(ll));
        for (ll i = 0LL; i < n; i++)
            L[i] = llrand(2LL, 200000LL);   // between 2 and 2*10^5 included
        printf("%lld\n", n);
        print_array(L, n, "%lld");
        res1 = max2prod(n, L);
        res2 = max2prod_slow(n, L);
        if (res1 != res2) {
            printf("Wrong: %lld %lld\n", res1, res2);
            run = 0;
        }
        else
            puts("OK");
        free(L);
    }
}

void main_function(int argc, char *argv[]) {
    ll n, *L;
    scanf("%lld", &n);
    L = malloc(n * sizeof(ll));
    for (ll i = 0; i < n; i++) {
        scanf("%lld", &L[i]);
    }
    printf("%lld\n", max2prod(n, L));
    free(L);
}

int main(int argc, char *argv[]) {
    //stress_test(argc, argv);
    main_function(argc, argv);
    return 0;
}
