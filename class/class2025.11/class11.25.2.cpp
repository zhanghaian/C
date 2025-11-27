#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int a[12][12] = {0};

    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int num =1;

    while ( num <= n * n ) {
        for ( int i = left; i <= right; i++ ) {
            a[top][i] = num++;
        }
            top++;

        for ( int i = top; i <= bottom; i++ ) { 
            a[i][right] = num++;
        }
            right--;
        
        if ( top < bottom ) {
            for ( int i = right; i >= left; i-- ) {
                a[bottom][i] = num++;
            }
            bottom--;
        
        if ( left <= right ) {
            for ( int i = bottom; i >= top; i-- )
                a[i][left] = num++;
        }
        left++;
        }
    }

    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            printf("%-4d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}