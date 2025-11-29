#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    int a[100][100];

    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            scanf("%d", &a[i][j]);
        }
    }

    int first = 1;
    int k =0;
    for ( k = 0; k <= 2 * n - 2; k++ ) {
        if ( k % 2 == 0 ) {
            int i_start = ( k < n ) ? 0 : k - ( n - 1 );
            int i_end = ( k < n ) ? k : ( n - 1 );
            for ( int i = i_start; i < i_end; i++ ) {
                int j = k - 1;
                if ( !first ) printf(" ");
                printf("%d", a[i][j]);
                first = 0;
            }
        } else {
            int i_start = ( k < n ) ? 0 : k - ( n - 1 );
            int i_end = ( k < n ) ? k : (n-1);
            for (int i = i_start; i <= i_end; i++) {
                int j = k - i;
                if (!first) printf(" ");
                printf("%d", a[i][j]);
                first = 0;
            }
        }
    }

    printf("\n");
    return 0;
}