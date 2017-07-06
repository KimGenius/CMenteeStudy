//
// Created by young on 2017-07-06.
//

#include <stdio.h>

int main() {
    int a = 0;
    int *b = &a;
    printf("a : %d, &a : %p\n", a, &a);
    printf("b : %p, *b : %d\n", b, *b);

    *b = 300;
    printf("a : %d, &a : %p\n", a, &a);
    printf("b : %p, *b : %d\n", b, *b);
    return 0;
}
