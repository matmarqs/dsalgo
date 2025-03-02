#include <stdio.h>

int main() {
    int money;
    scanf("%d", &money);
    int num_10, num_5, num_1;
    num_10 = money / 10;
    money %= 10;
    num_5 = money / 5;
    money %= 5;
    num_1 = money;
    printf("%d\n", num_10 + num_5 + num_1);
    return 0;
}
