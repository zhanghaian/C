#include <stdio.h>

int main() {

    int a[7][2];
    int sum[100] = {0};
    int k = 1;

    for ( int i = 0; i < 7; i++ ) {
        scanf("%d %d", &a[i][0], &a[i][1]);
        sum[i] = a[i][0] + a[i][1];
    }

    int m, n;
    for ( int i = 0; i < 7; i++ ) {
        if ( sum[i] > 8 ) {
            k = 0;
            break;
        }
    }

    m = sum[0];
    for ( int i = 0; i < 7; i++ ) {
        if ( m < sum[i] ) {
            m = sum[i];
            n = i + 1;
        }
    }
    

    if ( k == 1 ) {
        printf("0");
    } else {
        printf("%d\n", n);
    }

    return 0;
}