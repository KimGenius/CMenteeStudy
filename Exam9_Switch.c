//
// Created by young on 2017-07-06.
//

#include <stdio.h>

int main() {
    int a = 3;
    switch (a) {
        case 1:
            printf("a == 1");
            break;
        case 2:
            printf("a == 2");
            break;
        case 3:
            printf("a == 3");
            break;
        default:
            printf("default");
            break;
    }
    return 0;
}