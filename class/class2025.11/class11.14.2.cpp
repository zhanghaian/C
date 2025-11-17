#include <stdio.h>
#include <string.h>

int main() {
    char input[300];
    fgets(input, sizeof(input), stdin);

    char tokens[50][25]; 
    int count = 0;

    char *p = strtok(input, " \n");
    while (p != NULL) {
        strcpy(tokens[count++], p);
        p = strtok(NULL, " \n");
    }

    char opts[50][25];
    int opt_count = 0;
    for (int i = 1; i < count; i++) {
        if (tokens[i][0] == '-') {
            int exist = 0;
            for (int j = 0; j < opt_count; j++) {
                if (strcmp(opts[j], tokens[i]) == 0) {
                    exist = 1;
                    break;
                }
            }
            if (!exist) {
                strcpy(opts[opt_count++], tokens[i]);
            }
        }
    }

    if (opt_count == 0) {
        printf("no");
        return 0;
    }

    for (int i = 0; i < opt_count - 1; i++) {
        for (int j = i + 1; j < opt_count; j++) {
            if (strcmp(opts[i], opts[j]) > 0) {
                char temp[25];
                strcpy(temp, opts[i]);
                strcpy(opts[i], opts[j]);
                strcpy(opts[j], temp);
            }
        }
    }

    for (int i = 0; i < opt_count; i++) {
        if (i) printf(" ");
        printf("%s", opts[i]);
    }

    return 0;
}
