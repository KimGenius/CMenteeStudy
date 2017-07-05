//
// Created by young on 2017-07-05.
//

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define MAX 10

struct NODE {
    int data;
    struct NODE *link;
};

struct NODE *top = NULL;
int sp = 0;

bool PUSH(int value) {
    if (sp >= MAX) {
        printf("오버플로\n");
        return false;
    }

    struct NODE *NewNode = (struct NODE *) malloc(sizeof(NewNode));

    NewNode->data = value;
    NewNode->link = top;

    top = NewNode;
    sp++;
    printf("PUSH[%d]\n", top->data);
    return true;
}

bool POP() {
    struct NODE *DelNode = top;
    if (sp == 0) {
        printf("언더플로\n");
        return false;
    }
    printf("POP() => %d\n", top->data);
    top = top->link;
    free(DelNode);
    sp--;
    return true;
}

int main() {
    int i;
    for (i = 1; i < 12; i++) {
        PUSH(i * 10);
    }
    for (i = 1; i < 12; i++) {
        POP();
    }
    return 0;
}