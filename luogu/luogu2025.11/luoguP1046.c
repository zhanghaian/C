#include <stdio.h>

int main() {

    int a[10] = {0};
    for ( int i = 0; i < 10; i++ ) {
        scanf("%d", &a[i]);
    }
    
    int n, cnt;
    cnt = 0;
    scanf("%d", &n);

    for ( int j = 0; j < 10; j++ ) {
        if ( a [j] <= ( n + 30 ) ) {
            cnt++;
        }
    }

    printf("%d\n", cnt);

    return 0;
}