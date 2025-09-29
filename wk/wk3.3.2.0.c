#include <stdio.h>

int main() {
    int x = 0;
    scanf("%d", &x);

    if ( x < 0 ){
        printf("x=-1\n");
        x = -1;
    } else if ( x == 0 ) {
        printf("x=0\n");
    } else {
        printf("x= %d\n", x = 2 * x);
    }
}