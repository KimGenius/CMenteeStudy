//
// Created by young on 2017-07-06.
//

#include <stdio.h>
#include <malloc.h>

int main() {
    int *p = malloc(100); // int는 4byte 이므로 100/4 = 25 총 25개 그룹이 생김
    printf("%d", sizeof(*p));

    char *p_name;
    p_name = malloc(32);
    if (p_name != NULL) {
        gets(p_name);
        printf("%s\n", p_name);
        free(p_name);
    } else {
        printf("메모리 할당 실패");
    }
    return 0;
}