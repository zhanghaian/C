#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int sum, num;
    sum = a * 10 + b;
    num = sum / 19;

    printf("%d\n", num);

    return 0;
}