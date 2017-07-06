//
// Created by young on 2017-07-06.
//

#include <stdio.h>
#include <string.h>

int main() {
    char input_String[10] = {};
    gets(input_String);
    char input2[10];
    printf("input : %s\n", input_String);
    printf("input : %d\n", (int) sizeof(input_String));
    //sizeof도 10이고 input_string에 들어가는 값도 10개밖에 없는데 도대체 왜 다 나오지
    strcpy(input2, input_String);
    printf("asdf%s", input2);
    //이렇게 copy해도 10자리 넘게 나옴;
    return 0;
}