#include <stdio.h>

int main() {
    int x = 0;
    scanf("%d", &x);

    int f = 0;
    if ( x < 0 ) {
        f = -1;
    } else if ( x == 0 ) {
        f = 0;
    } else {
        f = 2 * x;
    }

    printf("x=%d\n", f);

    return 0;
}