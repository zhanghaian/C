#include <stdio.h>

typedef struct {
    int w;
    int h;
    int data[10][10];
} Image;

Image  rotate(Image src, int angle) {
    Image dest;

    if (angle == 0) {
        Image dest;

        if (angle == 0) {
            dest = src;
        } else if (angle == 90) {
            dest.w = src.h;
            dest.h = src.w;

            for (int i = 0; i < src.h; i++) {
                for ( int j = 0; j < src.w; j++) {
                    dest.data[j][src.h - 1 - i] = src.data[i][j];
                }
            }
        } else if (angle == 180) {
            dest.w = src.w;
            dest.h = src.h;

            for (int i = 0; i < src.h; i++) {
                for (int j = 0; j < src.w; j++) {
                    dest.data[src.h - 1 - i][src.w - 1 - j] = src.data[i][j];
                }
            }
        } else if (angle == 270) {
            dest.w = src.h;
            dest.h = src.w;

            for (int i = 0; i < src.h; i++) {
                for (int j = 0; j < src.w; j++) {
                    dest.data[src.w - 1 - j][i] = src.data[i][j];
                }
            }
        }
    }

    return dest;
}

int main() {
    Image src_img, out_img;
    int angle;

    if (scanf("%d %d", &src_img.w, &src_img.h) != 2) return 0;

    for (int i = 0; i < src_img.h; i++) {
        for (int j = 0; j < src_img.w; j++) {
            scanf("%d", &src_img.data[i][j]);
        }
    }

    scanf("%d", &angle);

    out_img = rotate(src_img, angle);

    printf("%d %d\n", out_img.w, out_img.h);
    for (int i = 0; i < out_img.h; i++) {
        for (int j = 0; j < out_img.w; j++) {
            printf("%d", out_img.data[i][j]);
            if (j < out_img.w - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;

}