#include <stdio.h>

int main() {
    int x = 0;
    scanf("%d", &x);
    
    int digit = 0;
    int ret = 0;
    
    while ( x > 0 ) {
        digit = x % 10; 
        printf("%d", digit);
        printf("x=%d,digit=%d,ret = %d\n", x, digit, ret );
        x /= 10;
    }
    printf("%d\n", ret);

    return 0;
}