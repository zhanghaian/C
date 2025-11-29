#include <stdio.h>

int main() {
    int k;
    scanf("%d", &k);

    double s = 0.0;

    for ( int i = 1; i > 0; i++ ) {
        s += 1.0 / i;
        if ( s > k ) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}