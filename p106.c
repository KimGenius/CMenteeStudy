//
// Created by young on 2017-07-09.
//

#include <stdio.h>

int main() {
    int n1 = 2, n2 = 4, n3;
    printf("연산 결과:참은 1, 거짓은 0 출력\n");

    n3 = (n1 > n2) ? 1 : 0;
    printf("%d > %d의 결과:%d\n", n1, n2, n3);

    n3 = (n1 < n2) ? 1 : 0;
    printf("%d > %d의 결과:%d\n", n1, n2, n3);

    n3 = (n1 == n2) ? 1 : 0;
    printf("%d > %d의 결과:%d\n", n1, n2, n3);

    n3 = (n1 != n2) ? 1 : 0;
    printf("%d > %d의 결과:%d\n", n1, n2, n3);

    n1 = 10, n2 = 3;
    int n4, n5;
    n3 = 0;

    n3 = (n1 > 1) || (n2 < 4);
    n4 = !(n1 + n2 <= 10);
    n5 = (n1 - n2 == 20) && (n1 % n2 == 2);
    printf("n3 = %d, n4 = %d, n5 = %d\n", n3, n4, n5);
    return 0;
}