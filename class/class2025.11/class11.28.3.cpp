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
        int max_len = 0;
        int max_start = -1;
        int max_end = -1;

        int j = 0;
        while ( j < n) {
            if ( a[i][j] == 1 ) {

                int start = j;
                int len = 0;

                while ( j < n && a[i][j] == 1 ) {
                    j++;
                    len++;
                }

                int end = j - 1;
                if ( len > max_len ) {
                    max_len = len;
                    max_start = start;
                    max_end = end;
                } 
            }else {
                    j++;
                } 
            
        }
        printf("%d %d\n", max_start, max_end);
    }

    return 0;
}