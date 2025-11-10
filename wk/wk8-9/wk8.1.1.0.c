#include <stdio.h>

int main() {
    double sum;
    int x, cnt;
    cnt = 0;
    int number[100];
    scanf("%d", &x);
    while ( x != 1 ) {
        number[cnt] = x;
        sum += x;
        cnt++;
        scanf("%d", &x);
    }
    if ( cnt > 0 ) {
        printf("%f\n", sum/cnt);
        int i;
        for ( i = 0; i < cnt; i++ ) {
            if ( number[i] > sum/cnt ) {
                printf("%d\n", number[i]);

            }
        }

    }

    return 0;
}