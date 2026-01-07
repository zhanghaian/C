#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b);

typedef struct {
    char name[13];
    int wins;
    int points;
} Team;

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    Team teams[10];
    for (int i = 0; i < n; i++) {
        scanf("%s", teams[i].name);
        teams[i].wins = 0;
        teams[i].points = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int score_code;
            scanf("%d", &score_code);

            if (score_code == 3 || score_code == 4) {
                teams[i].wins += 1;
                teams[i].points += 3;
            } else if (score_code == 5) {
                teams[i].wins += 1;
                teams[i].points += 2;
            } else if (score_code == -5) {
                teams[i].points += 1;
            }
        }
    }

    qsort(teams, n, sizeof(Team), compare);

    for (int i = 0; i < n; i++) {
        printf("%s %d %d\n", teams[i].name, teams[i].wins, teams[i].points);
    }

    return 0;
}

int compare(const void *a, const void *b) {
    Team *t1 = (Team *) a;
    Team *t2 = (Team *) b;

    if (t1->wins != t2->wins) {
        return t2->wins - t1->wins;
    }

    if (t1->points != t2->points) {
        return t2->points - t1->points;
    }

    return strcmp(t1->name, t2->name);
}
