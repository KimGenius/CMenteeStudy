//
// Created by young on 2017-07-05.
//

/*
 * 아래의 코드는 큐를 연결리스트를 이용해 구현한 코드이다
 * 코드의 빈 칸을 채워 넣고 각 빈 칸의 의미에 대해 설명하고, (a는 10점, b~f는 15점) 주어진 main
 * 함수에 따른 최종 결과를 서술하세요 (15점)
 * (단, ADD, DELETE 실행 시,어떤 데이터를 삽입 혹은 삭제했다는 것을 나타내는 출력문을 출력하지 않는다.
 */

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define MAX 100

struct NODE {
    int data;
    struct NODE *link; // a 10점 //다음 NODE를 가르켜야 되서 NODE형태로 *link로 포인터 변수를 선언함
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

    if (count == 0) { // b 15점 //만약에 값이 없으면 rear랑 front모두 같은 값을 가르켜야 되니 값이 없는걸 체크하기 위해 count == 0인지 체크한다.
        rear = pNODE;
        front = pNODE;
    } else {
        rear->link = pNODE;
        rear = pNODE;  // c 15점 //위에서 원래 끝 값 링크에 새로운 데이터를 넣었으면 이제 원래 끝 값에 새로운 데이터를 넣어줘야함
    }
    count++;  // d 15점 //
}

bool DELETE() {
    if (count == 0) {
        printf("큐 언더플로\n");
        return false;
    }
    struct NODE *pDelNODE = front;
    front = front->link;  // e 15점 //지우기 전에 처음 값을 그 다음 값으로 넣어줌
    free(pDelNODE);
    count--;

    if (count == 0) {
        front = NULL;
        rear = NULL;
    }
    return true;
}

void PrintQ() {
    printf("큐 : ");
    struct NODE *pNODE = front;
    while (pNODE != NULL) {
        printf(" %d ", pNODE->data);
        pNODE = pNODE->link;  // f 15점 //출력을 할 때에 다음 데이터를 가르키고 반복해야 하니 pNODE에 다음 링크의 값을 넣어줌
    }
    printf("\n");
}

int main() {
    ADD(10);
    ADD(20);
    PrintQ();
    DELETE();
    PrintQ();
    return 0;
}