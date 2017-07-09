//
// Created by young on 2017-07-09.
//

#include <stdio.h>

int main() {
    int num, temp, sum = 0;
    printf("정수?");
    scanf("%d", &num);
    //num = 123
    while (num > 0) {
        printf("%d", (num % 10));// 12 % 10 = 2 1
        temp = num % 10; // 123%10 12%10 = 2
        sum = sum + temp; // 0 + 3 = sum = 3  3+2 =  sum = 5 + 1 6
        num = num / 10; //123 /10 = 12 12 /10 = 1
    }
    printf("합 : %d", sum);
    return 0;
}