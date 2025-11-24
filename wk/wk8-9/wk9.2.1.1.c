#include <stdio.h>

int main(void) {
    char ac[] = {0,1,2,3,4,5,6,7,8,9};
    char *p = &ac[0];
    int i;
    for ( i = 0; i < sizeof(ac)/sizeof(ac[0]); i++) {
        printf("%d\t", ac[i]);
    }
    printf("\n");

    return 0;
}