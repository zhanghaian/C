#include <stdio.h>

int main() {
    unsigned long long x, n;
    scanf("%llu %llu", &x, &n);

    unsigned long long sum = 1;
    unsigned long long cur = 1;

    for (unsigned long long i = 1; i <= n; i++) {
        cur *= x;
        sum += cur;
    }

    printf("%llu", sum);

    return 0;
}