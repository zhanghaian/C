#include <stdio.h>

int main() {
    int x, n;
    if (scanf("%d %d", &x, &n) != 2) return 0;

    long long total_dist = 0;
    for (long long i = 0; i < n; i++) {
        int current_day = (x + i - 1) % 7 + 1;
        if (current_day != 6 && current_day != 7) {
            total_dist += 250;
        }
    }

    printf("%lld", total_dist);

    return 0;
}