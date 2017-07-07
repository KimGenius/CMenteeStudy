//
// Created by young on 2017-07-05.
//
#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int QUEUE[MAX] = {0,}; //QUEUE 배열을 MAX크기로 선언 후 0번째에 0 값 넣어줌
int front = 0; // front 즉, 앞의 값을 0으로
int rear = -1; //rear는 끝의 값인데 아직 아무것도 없으므로 -1로 넣어줌

bool ADD(int value) {
    if (rear >= MAX - 1) { //rear가 만약 MAX의 값보다 크면
        // -1을 하는 이유는 rear는 배열의 위치를 나타내기 위함이고 MAX는 최대 크기 자체인데
        // 최대 크기의 최소값은 1이고 배열은 0부터 시작하여 값을 맞춰주기 위해 -1을 함 MAX-1 대신에 rear+1을 해도 상관없음
        printf("큐 오버플로\n"); // 펑
        return false; //끝
    }
    rear++; //rear의 값을 증가시켜서 추가된게 몇번째인지 알려주기위함
    QUEUE[rear] = value; //추가된 rear값 QUERE 공간에 넣은 value를 넣어줌
    printf("ADD : %d\n", value); //추가된 값 알려줌
    return true; //끝
}

bool DELETE() {
    int value; //value를 선언해줌
    if (front > rear) { //front가 rear보다 크면 이 경우는 더 값이 없을 경우
        printf("큐 오버플로\n"); //펑
        return false; //끝
    }

    value = QUEUE[front]; //지워지는 값 저장
    front++; //front를 늘려줘서 한칸 당김

    printf("DELETE : %d \n", value); //지워진 값이 뭘까요
    return true; //끝
}

void PRINTQ() {
    printf("큐(front : %d : rear : %d)\n", front, rear); //현재 front와 queue의 값을 출력
    for (int i = front; i <= rear; i++) { //front의 값을 i에 넣어주고 i가 rear가 될때까지 슉슉
        printf("%d\n", QUEUE[i]); //i번째의 값 출력
    }
    printf("\n");
}

int main() {
    for (int i = 1; i <= 5; ++i) {
        ADD(i * 10); //값 추가
    }
    PRINTQ();
    DELETE();
    PRINTQ();

    return 0;
}