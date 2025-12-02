#include <stdio.h>
#include <stdlib.h>


int main() {

    int n, m;
    scanf("%d", &n);

    int rev = 0;
    m = abs(n);
    while ( m > 0 ) {
        rev = rev * 10 + m % 10;
        m /= 10;
    }

    if ( n > 0 ) {
        printf("%d\n", rev);
    } else {
        printf("-%d\n", rev);
    }

    return 0;
}