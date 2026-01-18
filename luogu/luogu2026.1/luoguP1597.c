#include <stdio.h>
#include <string.h>

int main() {
    char s[300];
    int val[3] = {0, 0, 0};

    if (scanf("%s", s) != 1) return 0;

    int len = strlen(s);
    for (int i = 0; i < len; i += 5) {
        int left = s[i] - 'a';
        char right = s[i + 3];

        if (right >= '0' && right <= '9') {
            val[left] = right - '0';
        } else {
            val[left] = val[right - 'a'];
        }
    }

    printf("%d %d %d\n", val[0], val[1], val[2]);

    return 0;
}