#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int score[4];
    int total;
    int weighted;
} Student;

int cmp(const void *a, const void *b){
    Student *s1 = (Student *)a;
    Student *s2 = (Student *)b;

    if (s1->weighted != s2->weighted)
        return s2->weighted - s1->weighted;

        if (s1->total != s2->total)
            return s2->total -s1->total;

        return s1->id - s2->id;
}

void sort4(int a[]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (a[j] < a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    Student stu[100];

    for (int i = 0; i < N; i++) {
        scanf("%d", &stu[i].id);

        stu[i].total = 0;

        for (int j = 0; j < 4; j++) {
            scanf("%d", &stu[i].score[j]);
            stu[i].total += stu[i].score[j];
        }

        sort4(stu[i].score);

        stu[i].weighted =
        (stu[i].score[0] * 35 +
         stu[i].score[1] * 30 +
         stu[i].score[2] * 20 +
         stu[i].score[3] * 15) / 100;
    }

    qsort(stu, N, sizeof(Student), cmp);

    for (int i = 0; i < N; i++) {
        printf("%d %d %d\n", stu[i].id, stu[i].weighted, stu[i].total);
    }

    return 0;
}