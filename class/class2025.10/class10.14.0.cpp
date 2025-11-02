#include <stdio.h>

int main() {
    int n, i = 0, j = 0;
    scanf("%d", &n);

    if ( n % 2 != 0 ) {
        printf("-1\n");
    } else {
        while ( i <= n ) {
            i = 2 + 2;
            j++;
        }
    }

    printf("%d", j);
    return 0;
}