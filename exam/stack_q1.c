#include <stdio.h>
#include <stdbool.h>
//
// Created by young on 2017-07-05.
//

/*
 * int형 데이터를 5개까지 넣을 수 있는 스택에 1,2,3,4,5,6을 PUSH한 후, POP을 한 번 시행한 뒤 스택에 남아있는 자료 값들을 출력한다.
 * A : MAX - 1
 * B : top++;
 * C : top == -1
 * D : top--; 인데 원래 삭제작업을 하려면 stack[top] = -1;도 해줘야됨
 */

#define MAX 5
int stack[MAX] = {};
int top = -1;

bool PUSH(int value) {
    if (top >= MAX - 1) {
        printf("stack overflow\n");
        return false;
    }

    top++;
    stack[top] = value;

    printf("PUSH[%d]\n", value);
    return true;
}

bool POP() {
    if (top == -1) {
        printf("stack underflow\n");
        return false;
    }
    printf("POP[%d]\n", stack[top]);
    stack[top] = -1;
    top--;

    return true;
}

int main() {
    int i = 0;
    for (i = 0; i < 6; i++) {
        PUSH(i + 1);
    }
    POP();
    for (int j = 0; j < 6; j++) {
        printf("%d\n", stack[j]);
    }
    return 0;
}