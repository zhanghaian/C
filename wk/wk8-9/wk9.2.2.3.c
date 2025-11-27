#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int i;
    void *p;
    int cnt = 0;
    p = &i;
    free(NULL);

    return 0;
}