#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); 

    int counts[1001] = {0}; 
    int num;

    
    for (int i = 0; i <= n; i++) {  //多读了一个数 改为 i < n;
        scanf("%d", &num);
        if(num >= 0 && num <= 1000) { 
            counts[num]++;
        }
    }

    int sum = 0; 

    
    for (int i = 0; i <= 1000; i++) { 
        if (counts[i] == 1) {
            sum += i; 
        }
    }

    printf("%d", sum); 
    return 0;
}
