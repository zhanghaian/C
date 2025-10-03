#include <stdio.h>

int main() {
    int type = 0;
    scanf("%d", &type);

    if ( type == 1 )
        printf("你好\n");
    else if ( type == 2 )
        printf("早上好\n");
    else if ( type == 3 )
        printf("晚上好\n");
    else if ( type == 4 )
        printf("再见\n");
    else 
        printf("输入错误\n");

    return 0;
}