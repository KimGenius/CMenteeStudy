//
// Created by young on 2017-07-06.
//

#include <stdio.h>

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int b[5];
    for (int i = 0; i < 5; ++i) {
        b[i] = i;
        printf("a : %d b : %d\n", a[i], b[i]);
    }
    return 0;
}