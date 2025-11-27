#include <stdio.h>

int main() {
    const int ROWS = 3;
    const int COLS = 4;

    int matrix[ROWS][COLS];
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                return 1;
            }
        }
    }

    for (int j = 0; j < COLS; j++) { 
        for (int i = 0; i < ROWS; i++) { 
            printf("%d", matrix[i][j]);

            if (i < ROWS - 1) {
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}