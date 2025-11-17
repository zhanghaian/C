#include <stdio.h>

int main() {

    return 0;
}

int isPrime ( int x )
{
    int ret = 1;
    int i;
    int x;
    if ( x == 1 ) ret = 0;
    for ( i = 2; i < x; i++ ) {
        if ( x % i = 0 ) {
            ret = 0;
            break;
        }
    }
    return ret;
}