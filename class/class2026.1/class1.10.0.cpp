#include <stdio.h>

int main() {
    char s[105];
    scanf("%s", s);

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            printf("_");
            printf("%c", s[i] + 32);
        } else {
            printf("%c", s[i]);
        }
    }
    printf("\n");

    return 0;
}