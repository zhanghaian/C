#include <stdio.h>

int main () {

    int m, n, a, b;
    scanf("%d %d", &m, &n);

    int target;
    target = 2;
    int count = 0;


    for ( int i = m; i <= n; i++ ) {
        b = i;
        while ( b > 0 ) {
            a = b % 10;
            b = b / 10;
            if ( a == 2 ) {
                count++;
            }
        }
    }
    
    printf("%d\n", count);
    return 0;
}