#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    double a, b, c, price;
    price = 0;

    if (n > 400) {
        price = (n - 400) * 0.5663 + 250 * 0.4663 + 150 * 0.4463;
    } else if (n > 150) {
        price = (n - 150) * 0.4663 + 150 * 0.4463;
    } else {
        price = n * 0.4463;
    }

    printf("%.1f\n", price);
}