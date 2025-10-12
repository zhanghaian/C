#include <stdio.h>

//我首先应该把n输进去然后由n生成一个n位数记作x然后然后得到10^n到10^（n+1）位的数字
//之后需要将每一位的数字拆出来
//之后让每一位数字的n次幂相加是否等于原数
//然后按照顺序输出每一个数字占一行

int main() {
    int n;
    scanf("%d", &n);
    int a = 1, b, i;
    for ( i = 1; i <= n; i++ ) {
        a *= 10;
        
    }
    printf("%d\n", a);

    return 0;

}

