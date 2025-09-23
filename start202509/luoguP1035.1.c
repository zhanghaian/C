#include <stdio.h>
#include <stdbool.h>

bool excess(double sn, double k) {
    return sn > k;
}
int main() {
    int i = 1;
    double sn = 0, k;
    printf("请输入一个浮点数k:");
    scanf("%lf",&k);
    while (true) {
        sn +=(double)1 / (double)(i++);
        if(excess(sn,k)){
        printf("%d\n",i - 1);
        break;
    }
}
return 0;
}