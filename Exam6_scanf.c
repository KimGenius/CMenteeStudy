//
// Created by young on 2017-07-06.
//

#include <stdio.h>

int main() {
    int int_data;
    float float_data;
    char char_data[32];
//    %d int
//    %h short
//    %f float
//    %lf double
//    %c char
//    %s string 물론 C에서는 String 없음 공백이 포함되는 문자를 받는다면 gets가 더 좋음
    scanf("%d", &int_data);
    scanf("%f", &float_data);
    scanf("%s", char_data); //&기호를 안 넣는 이유 : 배열변수는 그 자체가 시작점을 가르키기 때문에
//    char_data의 길이보다 더 넣으면 int_data와 float_data에 영향을 준다 이유는 뭘까
    printf("input : %d, %f %s\n", int_data, float_data, char_data);
    return 0;
}