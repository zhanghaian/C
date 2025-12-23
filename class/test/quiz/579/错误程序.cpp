#include <stdio.h>

long long fibonacci(int n) {
    if(n == 1 || n == 2) {
        return 0;  // 1月或2月不是0兔子繁殖 而是1个没有繁殖能力的兔子 改为return 1;
    }
    long long first = 1, second = 1, fib = 0;
    for(int i = 3; i < n; i++) {  //i < n错误 少算了一次改为 i <= n;
        fib = first + second;
        first = second;
        second = fib;
    }
    return fib;  
}

int main() {
    int n;
    printf("请输入月份数：");
    scanf("%d", &n);  
    printf("%lld\n", fibonacci(n));  
    return 0;
}
