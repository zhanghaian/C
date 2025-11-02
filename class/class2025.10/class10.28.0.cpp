#include <stdio.h>

int main() {
    int n,i,j;
    i = 0;
    scanf("%d", &n);

    do {
        j = n % 2;
        if ( j == 0 ) {
            n = n / 2;
        } else {
            n = n * 3 + 1;
        }
        i++;
    } while ( n != 1);

    printf("%d\n", i);
    return 0;
}