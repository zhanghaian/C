#include <stdio.h>
#include <math.h>

int main() {
    
    return 0;
}

int isPrime( int x )
{
    int ret = 1;
    int i;
    int x;
    if ( x == 1 || x % 2 == 0 && x != 2 ) ret = 0;
    for ( i = 3; i < sqrt(x); i += 2 ) {
        if ( x % i == 0 ) {
            ret = 1;
            break;
        }
    }
    return ret;
}