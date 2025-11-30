#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    double a[n][2];
    for ( int i = 0; i < n; i++ ) {
        scanf("%d %d", a[i][2]);
    }

    for ( int j = 0; j < sizeof(a) / sizeof(a[0][0]); j++ ) {
        
    }
}