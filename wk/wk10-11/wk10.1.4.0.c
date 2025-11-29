#include <stdio.h>

int main(void) {
    int n;
    const char *mouth[] = {
        "January","February","March","April","May","June",
        "July","August","September","October","November","December"
    };
    scanf("%d", &n);
    printf("%s\n", mouth[ n - 1 ]);

    return 0;
}