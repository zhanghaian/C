#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int M = N * N;

    int a[10000];
    for ( int i = 0; i < M; i++ ) {
        scanf("%d", &a[i]);
    }
    
    for ( int j = 0; j < M; j++ ) {
        if ( j % 2 == 0 ) {
            int t = a[j];
            while ( t > 0 ) {
                printf("0");
                t--;
            }
        } else {
            int p = a[j];
            while ( p > 0 ) {
                printf("1");
                p--;
            }
        }
    }

    return 0;
}