#include <stdio.h>

int main() {
    
    int A[2][3], B[3][2], C[2][2] = {0};

    
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    
    for(int i = 0; i < 3; i++) { // i < 3 越界了 共两列应该为 i < 2
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {  // k < 2 不够 对于A B来说列行分别为3所以为 k < 3
                C[i][j] -= A[i][k] * B[k][j]; 
            }
        }
    }

    
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n"); 
    }

    return 0;
}
