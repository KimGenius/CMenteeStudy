//
// Created by young on 2017-07-09.
//

#include <stdio.h>

int main() {
    int fibo[10];
    int i;
    fibo[0] = 0;
    fibo[1] = 1;
//    for (i = 1; i < 9; i++) { // 0 1 1 2 3 5 8....
//        fibo[i + 1] = fibo[i] + fibo[i - 1];
//    }
    for (i = 0; i <= 7; i++) {
        // 0 1 2 3 4 5 6 7 8 9
        // 0 1 1 2 3 5 8 13 21 34
        fibo[i + 2] = fibo[i + 1] + fibo[i];
    }
    for (int j = 0; j < 10; j++) {
        printf("%d ", fibo[j]);
    }
    return 0;
}