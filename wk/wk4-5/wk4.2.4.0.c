#include <stdio.h>

int main() {
    int x = 0;
    scanf("%d", &x);

    int digital = 0;
    digital = x % 10; 
    x /= 10;
}