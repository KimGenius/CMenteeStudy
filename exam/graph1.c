//
// Created by young on 2017-07-05.
//

#include <stdio.h>

#define SIZE 100

void main() {
    int G[SIZE][SIZE];
    int n, v, v1, v2;

    printf("\n 정점의 개수 입력 : ");
    scanf("%d", &n);
    printf("\n 간선의 개수 입력 : ");
    scanf("%d", &v);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            G[i][j] = 0;
//            정점 개수만큼 크기 만들어주는 초기화 작업
        }
    }

    for (int i = 0; i < v; i++) {
        printf("\n 간선 시작 정점 번호 : ");
        scanf("%d", &v1);
        printf("\n 간선 끝 정점 번호 : ");
        scanf("%d", &v2);
        G[v1 - 1][v2 - 1] = 1;
        G[v2 - 1][v1 - 1] = 1;
        //서로의 좌표에 0이 아닌 1을 넣어서 연결됨을 표시함
    }

    printf("\n\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d", G[i][j]);
            //값 전부 출력
        }
        printf("\n");
    }

}