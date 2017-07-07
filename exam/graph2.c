//
// Created by young on 2017-07-05.
//

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define SIZE 100
typedef struct _node {
    int num;
    struct _node *next;
} node; //alias 역할을 한다.

node *G[SIZE];
//size 만큼 선언

int main() {
    int n, v, v1, v2, i;
    node *t;

    printf("\n 정점의 개수 : ");
    scanf("%d", &n);
    printf("\n 간선의 개수 : ");
    scanf("%d", &v);

    for (int i = 0; i < n; i++) {
        G[i] = NULL;
    }//정점만큼 선언 값은 일단 빈 값, 즉 Null로 표시

    for (int i = 0; i < v; i++) {
        printf("\n 간선 시작 정점 번호 : ");
        scanf("%d", &v1);
        printf("\n 간선 끝 정점 번호 : ");
        scanf("%d", &v2);
        //간선 시작과 끝 입력

        t = (node *) malloc(sizeof(node));
        //t에 node 크기 만큼 메모리 동적 할당
        t->num = v2;
        //다음 번호 입력
        t->next = G[v1 - 1];
        //G[0] 에 t가 없으면 NULL이 들어갈테고 G[0]에 t가 있으면 그 t가 들어갈테니 계속 연결됨
        G[v1 - 1] = t; //그리고 이렇게 저장한 t를 다시 원래 자리에 슉

        t = (node *) malloc(sizeof(node));
        t->num = v1;
        t->next = G[v2 - 1];
        G[v2 - 1] = t;

        //서로 연결됨 ㅇㅇ
    }
    for (int i = 0; i < n; i++) {
        //정점 개수 만큼
        printf("\n 간선 %d", i + 1);
        for (t = G[i]; t != NULL; t = t->next) {
            /*위 코드는 다음 코드와 비슷함
             *  t = G[i];
             * while(t!=NULL) { 다음 값이 없을 경우 즉, NULL이면 그만!
             *  t->num 값 출력
             *  t->next로 이동
             * }
             * */
            printf("-> %d", t->num);
        }
    }
//    system("pause");
    return 0;
}