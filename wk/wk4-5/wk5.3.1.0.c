#include <stdio.h>

int main() {
    double n = 0;
    double a = 0;
    double sum = 0;

    scanf("%lf", &n);

    for ( a = 1; a <= n; a++ ) {
        sum += 1 / a;
    }

    printf("sum = %.6lf\n", sum);

    return 0;
}