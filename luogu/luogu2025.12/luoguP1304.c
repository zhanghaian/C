#include <stdio.h>

int isPrime(int x);
int main() {
    int N;
    scanf("%d", &N);
    for ( int i = 4; i <= N; i += 2 ) {
        for ( int j = 2; j <= i / 2; j++ ) {
            int k = i - j;
            if ( isPrime(j) && isPrime(k) ) {
                printf("%d=%d+%d\n", i, j, k);
                break;
            }
        }
    }

    return 0;
}


int isPrime(int x)
{
    if ( x <= 1 ) return 0;
    for ( int i = 2; i * i <= x; i++ ) {
        if ( x % i == 0 ) return 0;
    }

    return 1;
}