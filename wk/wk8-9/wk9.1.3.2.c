#include <stdio.h>

int divide ( int a, int b, int *result );
int main() {
    int a, b, c;
    a = 5;
    b = 2;
    if ( divide( a, b, &c ) ) {
        printf("%d/%d = %d", a, b, c);
    }
    printf("\n");
    return 0;
}

int divide ( int a, int b, int *result )
{
    int ret = 1;
    if ( b == 0 ) ret = 0;
    else {
        *result = a / b;
    }
    return ret;
}