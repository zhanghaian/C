#include <stdio.h>

int main() {
    long long x = 0;
    int n = 0;

    scanf("%lld", &x);

    n++;
    x /= 10;
    while ( x > 0 ) {
        n++;
        x /= 10;
    }
    
    printf("%d\n", n);

    return 0;
}