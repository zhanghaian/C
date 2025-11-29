#include <stdio.h>

int main() {
    int budget[12] = {0};
    for ( int i = 0; i < 12; i++ ) {
        scanf("%d", &budget[i]);
    }

    int left = 0;
    int saved = 0;

    for ( int mouth = 0; mouth < 12; mouth++ ) {

        left += 300;
        if ( left < budget[mouth] ) {
            printf("-%d\n", mouth + 1 );
            return 0;
        }

        int remain = left - budget[mouth];

        if ( remain >= 100 ) {
            int store = ( remain / 100 ) * 100;
            saved += store;
            left = remain - store;
        } else {
            left = remain;
        }
    }

    left += saved * 120/100;
    printf("%d\n", left);
    return 0;
}