#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }

    int c, d, total;
    d = 0;
    total = 0;
    for (int i = 0; i < n; i++) {
        c = a[i][0] + a[i][1];
        if (c > 8) {
            d = c - 8 + d;
        } else {
            d = c - 8 +d;
        }
        total += d;
    }
    printf("%d\n", total);

    return 0;
}