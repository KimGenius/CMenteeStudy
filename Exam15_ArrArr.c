//
// Created by young on 2017-07-06.
//

#include <stdio.h>

int main() {
    int a[5][5]; //2차원 배열 정사각형
    int b[5][5][5]; //3차원 배열 정육면체

    printf(" --- 2차원 ---\n");
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            a[i][j] = j;
            printf("%d\n", a[i][j]);
        }
    }

    printf(" --- 3차원 ---\n");
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) {
                b[i][j][k] = k;
                printf("%d ", b[i][j][k]);
            }
            printf("\n");
        }
    }
    return 0;
}