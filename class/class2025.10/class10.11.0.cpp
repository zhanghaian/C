#include <stdio.h>

int main() {
    long long x = 0;
    long long A = 0;
    long long salary = 0;
    scanf("%lld", &x);

    if ( x >= 3500 ) {
        A = x - 3500;
        if ( A >= 1500 ) {
            if ( A >= 4500 ) {
                if ( A >= 9000 ) {
                    if ( A >= 35000 ) {
                        A = 7745 + ( A - 35000 ) * 0.3;
                    } else {
                        A = 1245 + ( A - 9000 ) * 0.25;
                    }
                } else {
                    A = 345 + ( A - 4500 ) * 0.2;
                }
            } else {
                A = 45 + ( A - 1500 ) * 0.1;
            }
        } else {
            A =  A * 0.03;
        }
    } else {
        printf("%lld", x);
    }

    salary = x - A;
    printf("%lld\n", salary);
    return 0;
}