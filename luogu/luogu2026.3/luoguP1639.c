#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, x, y;

    scanf("%d %d %d %d", &a, &b, &x, &y);

    int d1 = abs(a-b);
    int d2 = abs(a-x) + abs(b-y);
    int d3 = abs(a-y) + abs(b-x);

    int ans = d1;

    if (d2 < ans) ans = d2;
    if (d3 < ans) ans = d3;

    printf("%d", ans);

    return 0;
}