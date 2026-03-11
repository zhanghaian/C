#include <stdio.h>
#include <string.h>

int main() {
    char code[256];
    int a = 0, b = 0, c = 0;

    if(!fgets(code, sizeof(code), stdin)) return 0;

    int len = strlen(code);

    for (int i = 0; i < len; i++) {
        if (code[i] == 'a' || code[i] == 'b' || code[i] == 'c') {
            char left = code[i];
            if (i + 3 < len && code[i+1] == ':' && code[i+2] == '=' ) {
                char right = code[i+3];
                int val = 0;
                if (right >= '0' && right <= '9') {
                    val = right - '0';
                } else if (right == 'a') {
                    val = a;
                } else if (right == 'b') {
                    val = b;
                } else if (right == 'c') {
                    val = c;
                }

                if (left == 'a') a = val;
                else if (left == 'b') b = val;
                else if (left == 'c') c =val;

                i += 3;
            }
        }
    }

    printf("%d %d %d\n", a, b, c);
    return 0;
}