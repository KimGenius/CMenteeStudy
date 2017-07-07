//
// Created by young on 2017-07-05.
//

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define MAX 10

struct NODE {
    int data; //안에 들어가는 데이터
    struct NODE *link; //다음을 가르키는 것
};

struct NODE *top = NULL; //처음에 top을 NULL로 생성
int sp = 0; //한계값 체크

bool PUSH(int value) {
    if (sp >= MAX) { //MAX를 넘었거나 같으면
        printf("오버플로\n");  //펑
        return false; //끝
    }

    struct NODE *NewNode = (struct NODE *) malloc(sizeof(NewNode));
    //NODE 형태 새로운 구조체 생성

    NewNode->data = value; //입력한 값을 data로 넣어줌
    NewNode->link = top; //원래 있던 데이터인 top을 링크로 걸어서 연결해줌

    top = NewNode; //top에 새로 생성한걸 넣어서 다음에 넣어도 바로 연결 가능하게 함
    sp++; //한계값 올라감
    printf("PUSH[%d]\n", top->data); //넣은 데이터 출력
    return true; //끝
}

bool POP() {
    struct NODE *DelNode = top; //지울 데이터를 저장
    if (sp == 0) { //만약 아무것도 없는데 지우려고 하면
        printf("언더플로\n"); //펑
        return false; //끝
    }
    top = top->link; //지워지기 전에 미리 top에 연결된 거로 top이 도망감
    printf("POP() => %d\n", top->data); //지워지는 데이터 값 출력 누가 사라지는지 알려줌
    free(DelNode); //메모리 증발
    sp--; //현재 값 --
    return true; //끝
}

int main() {
    int i;
    for (i = 1; i < 12; i++) { // 11번 넣음 일부러 오버플로 보여주려고 한번 더 넣는듯
        if (PUSH(i * 10)) { //return false, true 나눈 이유
            printf("성공\n");
        } else {
            printf("실패\n");
        }
    }
    for (i = 1; i < 12; i++) {
        POP();
    }
    return 0;
}