//
// Created by young on 2017-07-05.
//
#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int QUEUE[MAX] = {0,};
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
    for (int i = 1; i <= 5; ++i) {
        ADD(i * 10);
    }
    PRINTQ();
    DELETE();
    PRINTQ();

    return 0;
}