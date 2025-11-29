#include <stdio.h>

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    int count[16] = {0};

    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < m; j++ ) {
            int v;
            scanf("%d", &v);
            if ( v >= 0 && v < 16 ) {
                count[v]++;
            }
        }
    }

    for ( int i = 0; i < 16; i++ ) {
        if ( count[i] != 0 ) {
            printf("%d %d\n", i, count[i]);
        }
    }

    return 0;
} 