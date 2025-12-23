#include <stdio.h>

int main() {
    int N;
    printf("请输入需要转换的温度的个数：");
    scanf("%d", &N);

    double F;
    double C;

    printf("请输入%d个华氏温度值：\n", N);

    for (int i = 0; i <= N; i++) {//循环次数多一次,i <= N改为i < N
        scanf("%lf", &F);
        C = 5 / 9 * (F - 32);//结果是整数,5/9改为5.0/9
        printf("%.2f", C);


        if (i < N - 1) {
            printf(" ");
        }
    }

    return 0;
}
