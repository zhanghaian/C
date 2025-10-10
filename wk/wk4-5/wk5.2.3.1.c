#include <stdio.h>
// 找到第一个就退出
int main() {
    int x = 0;
    int one, two, five;
    int exit = 0;
    scanf("%d", &x);

    for ( one = 1; one < x * 10; one++ ) {
        for ( two = 1; two < x * 5; two++ ) {
            for ( five = 1; five < x * 2; five++ ) {
                if ( one + two * 2 + five * 5 == x * 10 ) {
                    printf("可以用%d个1角加%d个两角加%d个五角得到%d元\n", one, two, five, x);
                    exit = 1;
                    break;
                }
                if ( exit == 1 ) break;
            }
            if ( exit == 1 ) break;
        }
        if ( exit == 1 ) break;
    }

    return 0;
}