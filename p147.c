//
// Created by young on 2017-07-09.
//
//한 개의 정수를 입력받아 2~n까지의 수 가운데 소수를 출력하는 프로그램을 완성해보자 (단 소수는 1과 자신 외에는 약수를 갖기 않는 수이다.)
#include <stdio.h>

int main() {
    int i, j, num, count = 0;
    printf("숫자 입력 ?");
    scanf("%d", &num);
    for (int i = 2; i <= num; i++) { //입력받은 만큼 돌아
        for (int j = 1; j <= i; j++) { //동적으로 i만큼 돌아
            if (i % j == 0) { //i랑 j가 나눴을 때 나머지가 0이면
                count++; //++
            }
        }
        if (count == 2) { //i랑 j가 나눴을 때 0이 두개면 1과 자기자신이니까 소수로 판별하고 출력
            printf("%d ", i);
        }
        count = 0; // 그 후에 i 값들에게 영향을 안주기 위해 초기화
    }
}