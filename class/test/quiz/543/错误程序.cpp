#include <stdio.h>

int main() {
    int n, sum = 0;
    scanf("%d", &n);  

   
    for(int i = 1; i < n; i++) {  // i < n 错误 包括n i <= n
        if(i % 2 == 0) { // i % 2 == 0 是符合的偶数 改为 i % 2 != 0 
            sum += i;  
        }
    }

    printf("%d", sum);  
    return 0;
}
