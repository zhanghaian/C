#include <stdio.h>

int main(void) {
    int i;
    i = 0;
    int p;
    p = (int) &i;
    printf("0x%x\n", &i);
    printf("%p\n", &i);
    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof (int));

    return 0;
}