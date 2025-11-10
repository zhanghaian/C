#include <stdio.h>

void swap( int a, int b );

int main(void) {
    int a = 5;
    int b = 6;

    swap(a,b);

    {
        int i = 10;
        printf("%d\n", i);
        printf("%d\n", a);
    }
    {
        int a = 0;
        printf("%d\n", a);
    }
    {
        int a = 0;
        int a = 10;
        printf("%d", a);
    }
    printf("a=%d b=%d\n", a, b);

    return 0;
}

void swap ( int a, int b )
{
    int t;
    t = a;

}