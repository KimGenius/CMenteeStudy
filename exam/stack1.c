//
// Created by young on 2017-07-05.
//

#include <stdio.h>
#include <stdbool.h>

#define MAX 10
int stack[MAX] = {0,};
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
    top--;

    return true;
}

int main() {
    int i = 0;
    for (i = 0; i < 11; i++) {
        PUSH((i + 1) * 10);
    }
    for (int i = 0; i < 11; ++i) {
        POP();
    }

    return 0;
}