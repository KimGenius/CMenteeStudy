//
// Created by young on 2017-07-05.
//

#include <stdio.h>
#include <malloc.h>

struct NODE {
    struct NODE *left;
    char data;
    struct NODE *right;
};

struct NODE *CREATE(char data) {
    struct NODE *pNODE = NULL;
    pNODE = (struct NODE *) malloc(sizeof(pNODE));
    if (pNODE == NULL) {
        return NULL;
    }
    pNODE->left = NULL;
    pNODE->data = data;
    pNODE->right = NULL;
    printf("%c 노드 생성\n", pNODE->data);
    return pNODE;
}

void DELETE(struct NODE *pNODE) {
    if (pNODE != NULL) {
        if (pNODE->left != NULL) {
            DELETE(pNODE->left);
        }
        if (pNODE->right != NULL) {
            DELETE(pNODE->right);
        }
        printf("%c 노드 삭제\n", pNODE->data);
        free(pNODE);
    }
}

void PREORDERT(struct NODE *pNODE) {
    if (pNODE != NULL) {
        printf("%c", pNODE->data);
        PREORDERT(pNODE->left);
        PREORDERT(pNODE->right);
    }
}

void INORDERT(struct NODE *pNODE) {
    if (pNODE != NULL) {
        INORDERT(pNODE->left);
        printf("%c", pNODE->data);
        INORDERT(pNODE->right);
    }
}

void POSTORDERT(struct NODE *pNODE) {
    if (pNODE != NULL) {
        POSTORDERT(pNODE->left);
        POSTORDERT(pNODE->right);
        printf("%c", pNODE->data);
    }
}

int main() {
    struct NODE *pRoot = NULL;
    pRoot = CREATE('A');
    pRoot->left = CREATE('B');
    pRoot->right = CREATE('C');
    pRoot->left->left = CREATE('D');
    pRoot->left->right = CREATE('E');
    pRoot->right->left = CREATE('F');
    pRoot->right->right = CREATE('G');
    pRoot->left->right->left = CREATE('H');

    printf("\n전위 운행(Preorder) : ");
    PREORDERT(pRoot);
    printf("\n");

    printf("중위 운행(Preorder) : ");
    INORDERT(pRoot);
    printf("\n");

    printf("후위 운행(Preorder) : ");
    POSTORDERT(pRoot);
    printf("\n");
    return 0;
}