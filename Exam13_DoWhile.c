//
// Created by young on 2017-07-06.
//

#include <stdio.h>

int main() {
    int i = 0;

    do {
        printf("%d\n", i++);
    } while (i < 5);

    //조건이 맞지 않아도 일단 실행은 한다.
    do {
        printf("%d\n", i++);
    } while (i == 0);

    return 0;
}