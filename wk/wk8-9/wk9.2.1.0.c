#include <stdio.h>

int main(void) {
    char ac[] = {0,1,2,3,4,5,6,7,8,9};
    char *p = ac;
    printf("p  = %p\n", p);
    printf("p+1= %p\n", p+1);

    int ai[] = {0,1,2,3,4,5,6,7,8,9};
    int *q = ai;
    printf("q  = %p\n", q);
    printf("q+1= %p\n", q+1);

    double ao[] = {0,1,2,3,4,5,6,7,8,9};
    double *r = ao;
    printf("r  = %p\n", r);
    printf("r+1= %p\n", r+1);

    short au[] = {0,1,2,3,4,5,6,7,8,9};
    short *s = au;
    printf("s  = %p\n", s);
    printf("s+1=%p\n", s+1);

    printf("sizeof(char) = %lu\n", sizeof(char));
    printf("sizeof(int) = %lu\n", sizeof(int));
    printf("sizeof(double) = %lu\n", sizeof(double));
    printf("sizeof(short) = %lu\n", sizeof(short));


    printf("*(p+1) = %d\n", *(p+1));
    printf("*(q+1) = %d\n", *(q+1));

    char *p1 = &ac[5];
    printf("p1 - p = %ld\n", p1 - p);

    int *q1 = &ai[6];
    printf("q1 - q = %ld\n", q1 -q);

    //两个地址差除以sizeof类型，能放几个



    return 0;
}