//
// Created by young on 2017-10-12.
//

#include <stdio.h>

insertion_Sort(int a[], int count) {
    int i, j, k, temp;
    for (i = 0; i < count; i++) {
        temp = a[i];
        for (j = i - 1; j >= 0; j--) {
            if (temp >= a[j]) break; //추가하려는 수가 가장 뒤에 숫자랑 똑같거나 크면 그대로 종료하고
            a[j + 1] = a[j]; // 추가하려는 수가 더 작으면 큰 숫자를 한 단계 뒤로 보냄 (추가하려는 수의 공간을 만들기 위함)
        }
        a[j + 1] = temp; //추가함
        printf("step %d :", i);
        for (int k = 0; k <= i; ++k) {
            printf("%d ", a[k]);
        }
        printf("\n");
    }
}
int main() {
    int array[] = {5, 2, 8, 1, 9, 7};
    int i, c;
    c = sizeof(array) / sizeof(int);
    insertion_Sort(array, c);
    printf("정렬 후 데이터 : ");
    for (int i = 0; i < 6; ++i) {
        printf("%d ", array[i]);
    }

    return 0;
}