#include <stdio.h>

int main() {
    float m, n, price, discount;
    int i;
    scanf("%f %f", &m, &n);
    if ( m == 1.0 ) {
        i = 1;
        if ( n > 500 ) {
            price = n * 0.8;
        } else if ( n > 350 ) {
            price = n * 0.85;
        } else if ( n > 200 ) {
            price = n * 0.9;
        } else {
                price = n * 1.0;
        }
    } else if ( m == 0.0 ) {
        i = 0;
        if ( n > 500 ) {
            price = n * 0.9;
        } else if ( n > 350 ) {
            price = n * 0.95;
        } else {
            price = n * 1.0;
        }
    }
    discount = n - price;

    if ( i == 1 ) {
        printf("yes %.1f %.1f %.1f\n", n, price, discount);
    } else {
        printf("no %.1f %.1f %.1f\n", n, price, discount);
    }
    return 0;
}