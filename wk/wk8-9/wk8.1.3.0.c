#include <stdio.h>

int main(void) {

    const int number = 10;
    int x;
    int count[number];
    //或者可以写成 int count[number] = {0};直接省略了下边用for来是每一个为0的式子
    int i;

    for ( i = 0; i < number; i++ ) {
        count[i] = 0;
    }
    scanf("%d", &x);
    while ( x != -1 ) {
        if ( x >= 0 && x <= 9 ) {
            count[x] ++;
        }
        scanf("%d", &x);
    }
    for ( i = 0; i < number; i++ ) {
        printf("%d:%d\n", i, count[i]);
    }
    return 0;
}