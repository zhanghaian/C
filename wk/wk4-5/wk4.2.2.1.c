#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int number = rand()%100+1;
    int count = 0;
    int a = 0;
    printf("我已经想好了一个1到100之间的数字。");
    do {
        printf("请猜猜这个1到100之间的数字:");
        scanf("%d", &a);
        count++;
        if ( a > number ) {
            printf("你的数字猜大了。\n");
        } else if ( a < number ) {
            printf("你的数字猜小了。\n");
        }
        } while ( a != number );
    printf("太好了，你用了%d次就猜到了答案！\n", count);
    
    return 0;
    }
