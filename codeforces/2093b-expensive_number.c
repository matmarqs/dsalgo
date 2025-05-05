#include <stdio.h>

int len(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

int min_of_removed_digits(char *number, int n) {
    int i = n-1, count = 0;
    while (i >= 0 && number[i] == '0') { /* gets the index of last digit different than '0' */
        i--;
    } /* i = -1 if not found */
    /* this index i is going to survive */
    count += n-(i+1);
    for (int j = 0; j < i; j++) {
        if (number[j] != '0') {
            count++;
        }
    }
    return count;
}

int main() {
    int t;
    scanf("%d", &t);
    char number[101];
    for (int i = 0; i < t; i++) {
        scanf("%100s", number);
        int n = len(number);
        printf("%d\n", min_of_removed_digits(number, n));
    }
    return 0;
}
