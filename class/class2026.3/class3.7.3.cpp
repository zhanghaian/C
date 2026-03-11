#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    char birthday[9];
    char phone[18];
} Friend;

void sort(Friend f[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
           if(strcmp(f[j].birthday, f[j+1].birthday) < 0) {
                Friend temp = f[j];
                f[j] = f[j+1];
                f[j+1] = temp;
           }
        }
    }
}

int main() {
    int n;
    if(scanf("%d", &n) != 1) return 0;

    Friend f[10];

    for (int i = 0; i < n; i++) {
        scanf("%s %s %s", f[i].name, f[i].birthday, f[i].phone);
    }

    sort(f, n);

    for (int i = 0; i < n; i++) {
        printf("%s %s %s\n", f[i].name, f[i].birthday, f[i].phone);
    }

    return 0;
}