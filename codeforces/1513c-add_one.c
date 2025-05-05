/* INCOMPLETE */

#include <stdio.h>

int num_of_digits(int n) {
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

int len_after_operations(int d, int m) {
    return num_of_digits(d + m);
}

int len_str(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

int solve(char *n_str, int m) {
    int digit_count[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
                        /*{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }*/

    int N = len_str(n_str);
    for (int i = 0; i < N; i++) {
        digit_count[n_str[i] - '0']++;
    }

    int total_len = 0;
    for (int d = 0; d < 10; d++) {
        total_len += digit_count[d] * len_after_operations(d, m);
    }
    return total_len;
}

int main() {
    //int t;
    //scanf("%d", &t);
    //char n_str[11]; int m;
    //for (int i = 0; i < t; i++) {
    //    scanf("%10s %d", n_str, &m);    /* this line is unsafe */
    //    printf("%d\n", solve(n_str, m));
    //}
    printf("%d\n", len_after_operations(1, 100));
    return 0;
}
