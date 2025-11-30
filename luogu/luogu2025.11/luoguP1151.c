#include <stdio.h>

int main() {

    int k, t;
    t = 1;
    scanf("%d", &k);

    int a[3] = {0};
    for ( int i = 10000; i <= 30000; i++ ) {
        int a1, a2, a3;
        int b1, b2, b3;

        b1 = i / 100;
        b2 = (i % 10000) / 10;
        b3 = i % 1000;

        if ( b1 % k == 0 && b2 % k == 0 && b3 % k == 0 ) {
            printf("%d\n", i);
            t = 0;
        }
    }

    if ( t == 1 ) {
        printf("No");
    }

    return 0;
}