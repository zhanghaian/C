#include <stdio.h>

int n, board[25][25];
int white_count = 0, black_count = 0;

int check(int r, int c, int dr, int dc, int color) {
    for (int i = 0; i < 5; i++) {
        int nr = r + i * dr;
        int nc = c + i * dc;
        if (nr < 0 || nr >= n || nc >= n || board[nr][nc] != color) {
            return 0;
        }
    }
    return 1;
}

void print_coords(int r, int c, int dr, int dc) {
    int res[5][2];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (res[j][0] > res[j+1][0] || (res[j][0] == res[j+1][0] && res[j][1] > res[j+1][1])) {
                int tr = res[j][0], tc = res[j][1];
                res[j][0] = res[j+1][0]; res[j][1] = res[j+1][1];
                res[j+1][0] = tr; res[j+1][1] = tc;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        printf("%d %d\n", res[i][0], res[i][1]);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 1) white_count++;
            else if (board[i][j] == 2) black_count++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) continue;

            int color = board[i][j];
            int dr[] = {0, 1, 1, 1};
            int dc[] = {1, 0, 1, -1};

            for (int k = 0; k < 4; k++) {
                if (check(i, j, dr[k], dc[k], color)) {
                    printf("%d\n", color);
                    print_coords(i, j, dr[k], dc[k]);
                    return 0;
                }
            }
        }
    }

    printf("0 %d %d\n", white_count, black_count);
    return 0;
}