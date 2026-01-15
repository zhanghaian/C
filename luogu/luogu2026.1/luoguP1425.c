#include <stdio.h>

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    int total_time = 0;
    total_time = (c - a - 1) * 60 + 60 - b + d;

    int e, f;
    e = total_time / 60;
    f = total_time % 60;

    printf("%d %d\n", e, f);

    return 0;
}