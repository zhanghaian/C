#include <stdio.h>

int main() {

    int n, cnt = 0;
    scanf("%d", &n);

    int a[n];
    for ( int i = 0; i < n; i++ ) {
        scanf("%d", &a[i]);
    }

    for ( int j = 0; j < n - 2; j++ ) {
        if ( a[j+1] > a[j] && a[j+1] < a[j+2] ) {
            cnt++;
        }
    }

    printf("%d\n", cnt);
    return 0;
}