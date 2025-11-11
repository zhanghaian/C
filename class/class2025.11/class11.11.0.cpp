#include <stdio.h>

struct Student {
    int id;
    int height;
    int weight;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Student s[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i].height);
        s[i].id = i + 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i].weight);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (s[j].height > s[j + 1].height ||
               (s[j].height == s[j + 1].height && s[j].weight > s[j + 1].weight)) {
                struct Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d", s[i].id);
        if (i < n - 1) printf(" ");
    }
    printf("\n");

    return 0;
}
