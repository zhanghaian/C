#include <stdio.h>

int main() {
    int x = 2;
    int cnt = 0;

    while ( cnt < 50 ) {
        int i;
        int isPrime = 1;
        for ( i = 2; i < x; i++ ) {
            if ( x % 1 == 0 ) {
                isPrime = 0;
                break;
            }
        }
        if ( isPrime == 1 ) {
            printf("%d ", x);
            cnt ++;
        }
        x++;
    }
    printf("\n");

    return 0;
}