//
// Created by young on 2017-07-05.
//

#include <stdio.h>
#include <stdbool.h>

#define MAX 10 //최대값 지정
int stack[MAX] = {0,}; //최대값 만큼 배열 생성 후 0번째에 0 넣어줌 그냥 초기화작업
int top = -1; //아직 아무 값이 없으니 -1

bool PUSH(int value) {
    if (top >= MAX - 1) { //만약 최대값보다 크면
        printf("stack overflow\n"); //펑
        return false; //끝
    }

    top++; //현재 값 증가
    stack[top] = value; //증가된 공간에 데이터 넣어줌

    printf("PUSH[%d]\n", value); //어떤 값 넣었는지 알려줌
    return true; //끝
}

bool POP() {
    if (top == -1) { //top이 -1일 경우 즉, 아무 값이 없으면
        printf("stack underflow\n"); //펑
        return false; //끝
    }
    printf("POP[%d]\n", stack[top]); //사라진 값 알려줘
    top--; //top 한칸 내려줌

    return true;//끝
}

int main() {
    int i = 0;
    for (i = 0; i < 11; i++) {
        PUSH((i + 1) * 10); //값을 넣어줘
    }
    for (int i = 0; i < 11; ++i) {
        POP(); //빼줌
    }

    return 0;
}