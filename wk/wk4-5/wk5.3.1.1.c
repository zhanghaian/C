#include <stdio.h>

int main() {
    double n = 0;
    int a = 0;
    double sum = 0;
    double sign = 1.0;

    scanf("%lf", &n);
    for ( a = 1; a <= n; a++ ) {
        sum += sign * 1.0 / a;
        sign = -sign;
    }

    printf("%lf\n", sum);

    return 0;
}