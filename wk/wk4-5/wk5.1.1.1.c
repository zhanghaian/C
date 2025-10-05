#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d", &n);
    int fact = 1;

    int i = 1;
    //像一个计数循环，在到达某一个数之前，重复执行循环体
    for ( i = 1; i <= n; i++ ) {
        fact *= i;
    }
    printf("%d!=%d\n", n, fact);
}