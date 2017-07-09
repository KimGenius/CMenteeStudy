//
// Created by young on 2017-07-09.
//

#include <stdio.h>

int main() {
//    for (int i = 0; i < 3; ++i) { // 0 1 2 3
////        printf("*");
//        //A
//        for (int j = 0; j < 3; ++j) { // 0 1 2
//            printf("*");
//            //B
//        }
//        printf("\n");
//        //C
//    }

//    for (int i = 0; i < 5; ++i) { // 0 1 2 3 4
//        for (int j = 0; j <= i; ++j) { // 2 <= 2
//            printf("*");
//        }
//        printf("\n");
//    }

//    for (int i = 5; i >= 0; --i) { //5 4
//        for (int j = 0; j < i; ++j) { //0<5
//            printf("*");
//        }
//        printf("\n");
//    }

    for (int i = 1; i <= 5; i++) { // 1 2 3 4 5
        for (int j = 1; j <= i * 2; j += 2) { //
            printf("%d", j);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 5; i >= 1; i--) { // 1 2 3 4 5
        for (int j = 1; j <= i * 2; j += 2) { //
            printf("%d", j);
        }
        printf("\n");
    }
    return 0;
}