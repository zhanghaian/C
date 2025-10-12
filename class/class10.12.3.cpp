#include <stdio.h>

int main() {
    int y, m, d;
    scanf("%d %d", &y, &m);
    if (m == 2) {
        if ( (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) ) {
            d = 29;
        } else {
            d = 28;
        }
    } else if ( m == 4 || m == 6 || m == 9 || m == 11 ) {
        d = 30;
    } else {
        d = 31;
    }
    printf("%d\n", d);


    return 0;
}