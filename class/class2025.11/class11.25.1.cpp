#include <stdio.h>
#include <stdlib.h>


int main(void) {
    int i, j, n;
    scanf("%d", &n);
    if ( n <= 0 ) {
        return 0;
    }
    int **matrix = (int **) malloc(n * sizeof(int *));
    for ( i = 0; i < n; i++ ) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            if ( i == j ) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\n");

    }
    for ( i = 0; i < n; i++ ) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
} 