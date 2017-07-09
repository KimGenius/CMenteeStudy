//
// Created by young on 2017-07-09.
//

#include <stdio.h>

int main() {
    int a = 0;
    char c;
    printf("상품 코드 입력 : ");
    scanf("%d", &a);
    c = (a == 1) ? 'A' : 'B';
    printf("%c", c);
    return 0;
}