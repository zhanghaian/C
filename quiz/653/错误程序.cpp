#include <stdio.h>
#include <math.h>  


int isPrime(int num) {
    if (num <= 1) return 0;  
    if (num == 2) return 1;  
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;  
    }
    return 1;  
}

int main() {
    int m, n;
    printf("请输入区间范围（两个整数m和n，m ≤ n）：");
    scanf("%d %d", &m, &n);

    for (int i = m; i < n; i++) { 
        if (isPrime(i)) {
            printf("%d ", i);  
        }
    }
    return 0;
}
