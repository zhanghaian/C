#include <stdio.h>

int main(void) {

    int n, m;
    scanf("%d %d", &n, &m);

    int a[100][100];

    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < m; j++ ) {
            scanf("%d", &a[i][j]);
        }
    }

    for ( int j = 0; j < m; j++ ) {
        for ( int i = n - 1; i >= 0; i-- ) {
            printf("%d", a[i][j]);
            if ( i > 0 ) {
                printf(" ");
            }
        }
        printf("\n");
    }


    return 0;
}