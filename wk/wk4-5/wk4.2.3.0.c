#include <stdio.h>

int main() {
    int number = 0;
    int sum = 0;
    int count = 0;

    while ( number != -1 ) {
        sum += number;
        count++;
        scanf("%d", &number);   
    }
    printf("%f\n", (float)sum / count);
    
    return 0;
}
