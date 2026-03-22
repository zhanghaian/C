#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    int arr[MAX_SIZE];
    int count = 0;
    int m;
    char line[4096];

    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 0;
    }

    char *token = strtok(line, " \n\r");
    while (token != NULL && count < MAX_SIZE) {
        arr[count++] = atoi(token);
        token = strtok(NULL, " \n\r");
    }

    if (scanf("%d", &m) != 1) {
        return 0;
    }

    int first = 1;
    for (int i = 0; i < count; i++) {
        if (arr[i] != m) {
            if (!first) {
                printf(" ");
            }
            printf("%d", arr[i]);
            first = 0;
        }
    }
    printf("\n");

    return 0;
}