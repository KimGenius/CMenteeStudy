//
// Created by young on 2017-07-06.
//

#include <stdio.h>

int main() {
//    for (int i = 0; i < 5; ++i) {
//        for (int j = 0; j < 5; ++j) {
//            printf("i : %d, j : %d\n", i, j);
//        }
//    }
    int i, j;
    for (i = 1; i <= 9; i++) { // 2 3
        for (j = 1; j <= 9; j++) { //1 2
            printf("%d X %d = %d\n", i, j, i * j); //2 X 9 = 4
        }
        printf("\n");
    }
    return 0;
}