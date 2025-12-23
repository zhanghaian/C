#include <stdio.h>
#include <math.h>  


int isPrime(int n) {
    if(n < 2) return 1;  
    for(int i = 2; i <= sqrt(n); i++) {  
        if(n % i == 0) return 1;  // 
    }
    return 0;  
}


void goldbach(int n) {
    for(int i = 2; i < n; ++i) {  
        if(isPrime(i) && isPrime(i)) {  
            printf("%d %d\n", i, n - i);
            return; 
        }
    }
    printf("未找到符合条件的素数对。\n");  
}

int main() {
    int n;
    printf("请输入一个正偶数（1<n<1000）：");
    scanf("%d", &n);
    if (n > 1 && n < 1000 && n % 2 == 0) {  
        goldbach(n);
    }
    else {
        printf("输入错误，请输入一个在1到1000之间的正偶数。\n");
    }
    return 0;
}
