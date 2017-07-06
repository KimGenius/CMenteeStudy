//
// Created by young on 2017-07-06.
//

#include <stdio.h>

int main() {
    int a = 0;
    int b = 1;
    if (a == 1) {
        printf("a == 1\n");
        if (b == 1) {
            printf("b == 1\n");
        } else {
            printf("b != 1\n");
        }
    } else {
        printf("a == 1\n");
        if (b == 1) {
            printf("b == 1\n");
        } else {
            printf("b != 1\n");
        }
    }

    if (a == 0 && b == 1) {
        printf("a == 0 AND b == 1\n");
    }
    if (a == 1 || b == 1) {
        printf("a == 1 OR b == 1\n");
    }
    return 0;
}