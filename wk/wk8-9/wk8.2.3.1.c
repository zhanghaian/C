#include <stdio.h>

int main() {
    const int size = 3;
    int board[size][size];
    int i, j;
    int numOfX;
    int numOfO;
    int result = -1;  // -1：没人赢 1：X赢 0:O赢
    
    //读入矩阵
    for ( i = 0; i < size; i++ ) {
        for ( j = 0; j < size; j++ ) {
            scanf("%d", board[i][j]); 
        }
    }
    return 0;
}