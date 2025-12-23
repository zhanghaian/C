#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);  

    int matrix[100][100];  

    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);  
        }
    }

    
    for (int i = 0; i < m; i++) {
        int maxStart = -1, maxEnd = -1, maxLen = 0;  
        int currentStart = -1, currentLen = 0;  

        
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {  
                if (currentLen == 0) {
                    currentStart = j;  
                }
                currentLen++; 
            } else {
                if (currentLen > maxLen) {
                    
                    maxLen = currentLen;
                    maxStart = currentStart;
                    maxEnd = j - 1;
                }
                currentLen = 0;  
            }
        }

       
        if (currentLen > maxLen) {
            maxLen = currentLen;
            maxStart = currentStart;
            maxEnd = n;  //n下表错误 改为 n - 1；
        }

        
        if (maxLen > 0) {
            
            printf("%d %d\n", maxStart, maxEnd);
        } else {
            
            printf("-1 -1\n");
        }
    }
    return 0;
}