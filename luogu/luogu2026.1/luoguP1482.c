#include <stdio.h>

long long gcd(long long a, long long b);

int main() {
    long long a1, b1, a2, b2;

    if (scanf("%lld/%lld", &a1, &b1) != 2) return 0;
    if (scanf("%lld/%lld", &a2, &b2) != 2) return 0;

    long long final_num = a1 * a2;
    long long final_den = b1 * b2;

    long long common = gcd(final_num, final_den);
    final_num /= common;
    final_den /= common;

    printf("%lld %lld\n", final_den, final_num);

    return 0;
}

long long gcd(long long a, long long b) {
    while (b != 0) {
        a %= b;
        long long temp = a;
        a = b;
        b = temp;
    }
    return a;
}