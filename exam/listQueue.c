//
// Created by young on 2017-07-05.
//

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define MAX 100

struct NODE {
    int data;
    struct NODE *link;
};

struct NODE *front = NULL;
struct NODE *rear = NULL;
int count = 0;

bool ADD(int data) {
    if (count >= MAX) {
        printf("큐 오버플로\n");
        return false;
    }

    struct NODE *pNODE = (struct NODE *) malloc(sizeof(pNODE));
    pNODE->data = data;
    pNODE->link = NULL;

    if (count == 0) {
        rear = pNODE;
        front = pNODE;
    } else {
        rear->link = pNODE;
        rear = pNODE;
    }

    count++;
    printf("ADD : %d\n", data);
    return true;
}

bool DELETE(int *pdata) {
    if (count == 0) {
        printf("큐 언더플로\n");
        return false;
    }

    *pdata = front->data;
    struct NODE *pDelNODE = front;
    front = front->link;
    free(pDelNODE);

    count--;
    if (count == 0) {
        front = NULL;
        rear = NULL;
    }
    printf("DELETE : %d \n", *pdata);
    return true;
}

void PrintQ() {
    printf("큐 : ");
    struct NODE *pNODE = front;
    while (pNODE != NULL) {
        printf(" %d ", pNODE->data);
        pNODE = pNODE->link;
    }
    printf("\n");
}

int main() {
    int data = 0;
    for (int i = 1; i <= 4; ++i) {
        ADD(10 * i);
    }
    PrintQ();
    for (int j = 1; j <= 5; ++j) {
        DELETE(&data);
    }
    PrintQ();
    return 0;
}