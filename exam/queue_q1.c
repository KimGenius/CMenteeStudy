//
// Created by young on 2017-07-05.
//
/*
 * int형 데이터를 5개까지 넣을 수 있는 큐에 1,2,3,4,5,6을 ADD한 후,
 * DELETE를 한 번 시행한 뒤 스택에 남아있는 자료 값들을 출력한다.
 */
#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int QUEUE[MAX] = {};
int front = 0;
int rear = -1;

bool ADD(int value) {
    if (rear >= MAX - 1) {
        printf("큐 오버플로\n");
        return false;
    }
    rear++;
    QUEUE[rear] = value;
    printf("ADD : %d\n", value);
    return true;
}

bool DELETE() {
    int value;
    if (front > rear) {
        printf("큐 오버플로\n");
        return false;
    }

    value = QUEUE[front];
    front++;

    printf("DELETE : %d \n", value);
    return true;
}

void PRINTQ() {
    printf("큐(front : %d : rear : %d)\n", front, rear);
    for (int i = front; i <= rear; i++) {
        printf("%d\n", QUEUE[i]);
    }
    printf("\n");
}

int main() {
    for (int i = 0; i <= 5; ++i) {
        ADD(i + 1);
    }
    DELETE();
    PRINTQ();

    return 0;
}