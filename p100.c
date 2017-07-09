//
// Created by young on 2017-07-09.
//

#include <stdio.h>

int main() {
    int n1, n2, n3;
    printf("두 정수 입력 : ");
    scanf("%d %d", &n1, &n2);
//    if(n1 > n2) {
//        n3 = n1;
//    }else {
//        n3 = n2;
//    }
//    n3 = (n1 > n2) ? n1 : n2;
    n3 = (n1++ > --n2) ? n1 : n2;
    printf("더 큰 수 : %d", n3);
    return 0;
}