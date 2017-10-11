////
//// Created by young on 2017-07-06.
////
//
//#include <stdio.h>
//
//int main() {
////    for (int i = 0; i < 5; ++i) {
////        for (int j = 0; j < 5; ++j) {
////            printf("i : %d, j : %d\n", i, j);
////        }
////    }
//    int i, j;
//    for (i = 1; i <= 9; i++) { // 2 3
//        for (j = 1; j <= 9; j++) { //1 2
//            printf("%d X %d = %d\n", i, j, i * j); //2 X 9 = 4
//        }
//        printf("\n");
//    }
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../../../cygwin64/usr/include/stdlib.h"
#include "../../../../cygwin64/usr/include/time.h"
#include "../../../../cygwin64/usr/include/stdio.h"

int main(int argc, char *argv[]) {

    int ai; // 알파고
    int user; // 나
    int count; // 기회카운트
    char retry = 0; // 다시시도 = 재시도
    int limit;

    while (1) {
        count = 5;
        srand(time(0));

        printf("************ UP & DOWN ************\n\n"); // 역시 이런게임은 별표무늬
        while (1) {
            printf("범위를 정해주세요 : ");
            scanf("%d", &limit);
            if (limit <= 1) {
                printf("2 이상의 정수를 입력해주세요.\n");
            } else if (limit > 1) {
                break;
            }
        }

        ai = rand() % limit + 1;

        while (count > 0) {
            printf("남은기회 : %d번\n", count);
            printf("정수를 입력해주세요 ( 1 ~ %d 사이) : ", limit);

            fflush(stdin);

            if (scanf("%d", &user) == 0) {
                printf("\n 숫자를 입력하셔야 합니다 ~ (1 ~ %d 사이) : ", limit);
                continue;
            }
            if (ai == user) // 숫자가 같으면 정답
            {
                printf("\n 정 답 입 니 다 ~ \n");
                break;
            } else if ((user > limit) || (user < 1)) {
                printf("\n 1~%d사이 숫자를 입력해주세요\n", limit);
                continue;
            } else {
                printf("\n 틀렸습니다 !! ! \n");
                count--;

                if (ai < user) {
                    printf("DOWN !\n");
                } else {
                    printf("UP !!\n");
                }
            }
        }
        if (count == 0) {
            printf("GameOver !!\n");
            printf("정답 : %d\n", ai);
        }
    }
    return 0;
}