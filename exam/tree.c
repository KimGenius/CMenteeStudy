//
// Created by young on 2017-07-05.
//

#include <stdio.h>
#include <malloc.h>

struct NODE {
    struct NODE *left; //left와 (왼팔)
    char data; //자기 공간의 데이터
    struct NODE *right; //right를 생성 (오른팔)
};

struct NODE *CREATE(char data) {
    struct NODE *pNODE = NULL; //새로 생성될 데이터를 일단 NULL로 초기화
    pNODE = (struct NODE *) malloc(sizeof(pNODE)); //메모리 할당
    if (pNODE == NULL) { //pNODE가 NULL이면 아무 데이터가 없으면
        return NULL; //NULL 반환
    }
    pNODE->left = NULL; //left는 처음으로 생성했으니까 null
    pNODE->data = data; //자기 데이터 넣어주고
    pNODE->right = NULL; //right도 처음이니까 null
    printf("%c 노드 생성\n", pNODE->data); //생성된 값 알려줌
    return pNODE; //pNODE 데이터 반환
}

void DELETE(struct NODE *pNODE) {
    if (pNODE != NULL) { //넘겨받은 데이터가 NULL이 아니면
        if (pNODE->left != NULL) { //left가 NULL이 아니면
            DELETE(pNODE->left); //left도 지움
        }
        if (pNODE->right != NULL) { //right가 NULL이 아니면
            DELETE(pNODE->right); //right도 지움
            // 재귀함수로 작동하기 때문에 계속 타고 들어가서 결국 안에 안에 안에 안에 있는거까지 싹 다 지움
        }
        printf("%c 노드 삭제\n", pNODE->data);// 지워진 데이터 출력
        free(pNODE); //메모리 증발
    }
}

void PREORDERT(struct NODE *pNODE) {
    // 전위 운행은 data left right
    if (pNODE != NULL) { //넘겨받은 데이터가 값이 NULL이 아니면
        printf("%c", pNODE->data); //먼저 데이터 출력
        PREORDERT(pNODE->left); //left 들어감
        PREORDERT(pNODE->right); //right 들어감
        //이것도 역시 재귀함수라서 다 타고 들어가서 알려줌
    }
}

void INORDERT(struct NODE *pNODE) {
    // 중위 운행은 left data right
    if (pNODE != NULL) {
        INORDERT(pNODE->left); //left 들어감
        printf("%c", pNODE->data); //data 출력
        INORDERT(pNODE->right); //right 들어감
    }
}

void POSTORDERT(struct NODE *pNODE) {
    // 후위 운행은 left right data
    if (pNODE != NULL) {
        POSTORDERT(pNODE->left); //left 들어감
        POSTORDERT(pNODE->right); //right 들어감
        printf("%c", pNODE->data); //data 출력
    }
}

int main() {
    struct NODE *pRoot = NULL; //가장 상위 루트를 생성
    pRoot = CREATE('A'); //거기에 A를 넣어줌
    pRoot->left = CREATE('B'); //왼쪽에 B
    pRoot->right = CREATE('C'); //오른쪽에 C
    pRoot->left->left = CREATE('D'); //왼쪽에 왼쪽에 D
    pRoot->left->right = CREATE('E'); //왼쪽에 오른쪽에 E
    pRoot->right->left = CREATE('F'); //오른쪽에 왼쪽에 F
    pRoot->right->right = CREATE('G'); //오른쪽에 오른쪽에 G
    pRoot->left->right->left = CREATE('H'); //왼쪽에 오른쪽에 왼쪽에 H

    printf("\n전위 운행(Preordert) : ");
    PREORDERT(pRoot);
    printf("\n");

    printf("중위 운행(Inordert) : ");
    INORDERT(pRoot);
    printf("\n");

    printf("후위 운행(Postordert) : ");
    POSTORDERT(pRoot);
    printf("\n");
    return 0;
}