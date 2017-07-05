//
// Created by young on 2017-07-05.
//

#include <stdio.h>
#include <malloc.h>

#define SIZE 100
typedef struct _node {
    int num;
    struct _node *next;
} node;

node *G[SIZE];

int main() {
    int n, v, v1, v2, i;
    node *t;

    printf("\n 정점의 개수 : ");
    scanf("%d", &n);
    printf("\n 간선의 개수 : ");
    scanf("%d", &v);

    for (int i = 0; i < n; i++) {
        G[i] = NULL;
    }

    for (int i = 0; i < v; i++) {
        printf("\n 간선 시작 정점 번호 : ");
        scanf("%d", &v1);
        printf("\n 간선 끝 정점 번호 : ");
        scanf("%d", &v2);

        t = (node *) malloc(sizeof(node));
        t->num = v2;
        t->next = G[v1 - 1];
        G[v1 - 1] = t;

        t = (node *) malloc(sizeof(node));
        t->num = v1;
        t->next = G[v2 - 1];
        G[v2 - 1] = t;
    }
    for (int i = 0; i < n; i++) {
        printf("\n 간선 %d", i + 1);
        for (t = G[i]; t != NULL; t = t->next) {
            printf("-> %d", t->num);
        }
    }

    return 0;
}