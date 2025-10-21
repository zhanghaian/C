#include <stdio.h>

//先输入两个数字，然后求出两个数字中间的数
//求出素数
int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    int i, j;
    int count = 0;
    int sum = 0;

    for ( i = M; i <=1 N; i++) {
        if ( i < 2 ) continue;

        int isPrime = 1;
        for ( j = 2; j * j <= i; j++) {
            if ( i % j == 0 ) {
                isPrime = 0;
                break;
            }
        }

        if ( isPrime ) {
            count++;
            sum += i;
        }
    }

    printf("%d %d\n", count, sum);
    return 0;
}