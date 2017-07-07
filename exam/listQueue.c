//
// Created by young on 2017-07-05.
//

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define MAX 100

struct NODE {
    int data; //값 설정
    struct NODE *link; //다음 링크 설정
};

struct NODE *front = NULL; //앞 값 설정
struct NODE *rear = NULL; //끝 값 설정
int count = 0; //count로 몇개 했는지 체크

bool ADD(int data) {
    if (count >= MAX) { //최대보다 더 했으면
        printf("큐 오버플로\n"); //펑
        return false; //끝
    }

    struct NODE *pNODE = (struct NODE *) malloc(sizeof(pNODE)); //새로운 데이터 생성
    pNODE->data = data; //값 넣어줌
    pNODE->link = NULL; //링크

    if (count == 0) { //count가 0이면 첫 값을 추가하는 것임
        rear = pNODE; //그러니 끝의 값과
        front = pNODE; //앞의 값이 똑같이 새로 생성한 데이터로 넣어짐
    } else { //count가 0이 아니면 이미 값이 있다는 것
        rear->link = pNODE; //그러니 끝의 값->link에 데이터를 넣어주고
        rear = pNODE; //끝에 값엔 새로 생성된 데이터를 바로 추가
    }

    count++; //현재 값 추가
    printf("ADD : %d\n", data); //넣은 데이터 출력
    return true; //끝
}

bool DELETE(int *pdata) { //지워
    if (count == 0) { //0이면 아무 값도 없으니
        printf("큐 언더플로\n"); //펑
        return false; //끝
    }

    *pdata = front->data; //앞의 값의 데이터를 넣어줌
    struct NODE *pDelNODE = front; //새로 지울 데이터를 담아줌
    front = front->link; //앞의 값을 한칸 당겨줌
    free(pDelNODE); //새로 지울 데이터 증발

    count--; //현재 값 --
    if (count == 0) { //만약 count가 0이면 즉, 지운 후 아무 값이 없으면
        front = NULL; // 둘 다
        rear = NULL; // NULL로
    }
    printf("DELETE : %d \n", *pdata); //지워진 값 알려줌
    return true; // 끝
}

void PrintQ() {
    printf("큐 : ");
    struct NODE *pNODE = front; //앞의 값을 새로운 데이터에 담아줌
    while (pNODE != NULL) { //새로운 데이터가 NULL일 때 까지, 쉽게 말하면 더이상 데이터가 없을 때 까지
        printf(" %d ", pNODE->data); //데이터를 출력해줌
        pNODE = pNODE->link; //그 다음 데이터를 가르켜주는데 만약 그 다음이 없으면 null을 가져오겠죠
    }
    printf("\n"); //줄 바 꿈
}

int main() {
    int data = 0;
    for (int i = 1; i <= 4; ++i) {
        ADD(10 * i); //데이터를 추가해줘요
    }
    PrintQ(); //출력
    for (int j = 1; j <= 5; ++j) {
        DELETE(&data); //데이터를 지워요
    }
    PrintQ(); //출력
    return 0; //끝
}