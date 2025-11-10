#include <stdio.h>

void swap();
// void swap(void);
//标点符号(a,b)
//运算符((a,b))

int main() {
    int a = 5;
    int b = 6;

    swap(a,b);

    printf("a=%d b=%d", a, b);

    return 0;
}
void swap ( double a, double b )
