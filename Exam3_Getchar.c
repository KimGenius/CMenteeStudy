//
// Created by young on 2017-07-06.
//

#include <stdio.h>

int main() {
    int input_data;
    input_data = getchar();
    printf("input : %c\n",input_data);
//    getchar를 두번 쓰면 enter 값도 입력으로 처리되서 두번째 입력은 되지 않음
//    input_data = getchar();
//    printf("input : %c\n",input_data);

//    해결책
//    input_data = getchar();
//    getchar(); //임시로 getchar를 한번 더 해줘서 enter값을 처리함
//    printf("input %c\n", input_data);
//
//    input_data = getchar();
//    getchar();
//    printf("input %c\n", input_data);
    return 0;
}