#include <stdio.h>
#include <math.h>  
#include <stdbool.h>  


int fibonacci(int n) {
    int a = 0, b = 1, c;  
    for(int i = 2; i < n; ++i) { //应从第3项开始，i=3 
        c = a - b; //应为c=a+b
        a = b;
        b = c;
    }
    return a; //应返回b
}


bool isPrime(int n) {
    if(n <= 1) return false;
    if(n == 2) return true;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    printf("请输入整数n（1<n<=40）：");
    scanf("%d", &n);
//缺少校验n是否在1<n<=40的范围内
    
    int fibNum = fibonacci(n);
    
    
    if(isPrime(fibNum)) {
        printf("yes");
    } else {
        printf("%d", fibNum);
    }
    return 0;
}
