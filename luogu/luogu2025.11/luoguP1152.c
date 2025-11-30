#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    int isJolly = 1;
    scanf("%d", &n);

    int a[1000] = {0};
    for ( int i = 0; i < n; i++ ) {
        scanf("%d", &a[i]);
    }

    for ( int j = 0; j < ( n - 1 ); j++ ) {
        int b = abs(a[j] - a[j+1]);
        if ( b < 1 || b > (n - 1) ) {
            isJolly = 0;
        }
    }

    
    if ( isJolly == 1 ) {
        printf("Jolly\n");
    } else {
        printf("Not jolly\n");
    }


    return 0;
}