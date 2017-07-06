//
// Created by young on 2017-07-06.
//

#include <stdio.h>

int main() {
    int a = 0;
    int *b = &a;
    int **c = &b;
    printf("&a : %p, a = %d\n", &a, a);
    printf("b : %p, *b = %d\n", b, *b);
    printf("c : %p, **c = %d\n\n", c, **c);

    a = 15;
    printf("a = 15\n");
    printf("&a : %p, a = %d\n", &a, a);
    printf("b : %p, *b = %d\n", b, *b);
    printf("c : %p, **c = %d\n\n", c, **c);

    *b = 30;
    printf("*b = 30\n");
    printf("&a : %p, a = %d\n", &a, a);
    printf("b : %p, *b = %d\n", b, *b);
    printf("c : %p, **c = %d\n\n", c, **c);

    **c = 1000;
    printf("**c = 1000\n");
    printf("&a : %p, a = %d\n", &a, a);
    printf("b : %p, *b = %d\n", b, *b);
    printf("c : %p, **c = %d\n\n", c, **c);
    return 0;
}