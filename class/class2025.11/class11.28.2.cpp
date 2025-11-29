#include <stdio.h>

int main() {
    
    int m, n;
    scanf("%d %d", &m, &n);

    int a[100][100];

    for ( int i = 0; i < m; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            scanf("%d", &a[i][j]);
        }
    }

    for ( int i = 0; i < m; i++ ) {
        int min_col = 0;
        for ( int j = 1; j < n; j++ ) {

            if ( a[i][j] < a[i][min_col] ) {
                min_col = j;
            }

            int value = a[i][min_col];
            int s = 1;

            for ( int k = 0; k < m; k++ ) {
                if ( a[k][min_col] > value ) {
                    s = 0;
                    break;
                }
                
            }

            if ( s ) {
                printf("%d %d %d\n", i, min_col, value);
                return 0;
            }

        }
    }

    printf("no\n");


    return 0;
}