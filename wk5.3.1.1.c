#include <stdio.h>

int main() {
    int x = 0;
    int a = 0;

    scanf("%d", &x);

    do {
        a = x % 10;
        printf("%d ", a);
        if ( x >= 10 ) {
            printf(" ");
        }
        x = x / 10;
    } while ( x > 0 );

    printf("\n");
    return 0;
}