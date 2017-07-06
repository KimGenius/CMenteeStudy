//
// Created by young on 2017-07-06.
//

#include <stdio.h>

int main() {
    int a[5][5];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            a[i][j] = j;
            printf("%d", a[i][j]);
        }
    }
    return 0;
}