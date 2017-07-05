//
// Created by young on 2017-07-06.
//

#include <stdio.h>

int main() {

    int input_data = getchar();
    rewind(stdin); //표준 입력 버퍼 : stdin
    printf("input : %c\n", input_data);

    input_data = getchar();
    rewind(stdin);
    printf("input : %c\n", input_data);

//    원래 해결 되야 되는데 안되네?
    return 0;
}