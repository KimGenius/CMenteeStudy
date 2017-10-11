//
// Created by young on 2017-10-11.
//

#include <stdio.h>

void Selection_Sort(int a[], int n) {
    int i, j;
    int min, index;
    for (i = 0; i < n - 1; ++i) {
        min = a[i];
        index = i;
        for (j = i + 1; j < n; ++j) {
            if (min > a[j]) {
                min = a[j];
                index = j;
            }
        }
        a[index] = a[i];
        a[i] = min;
        printf("step %d : ", i);
        for (int k = 0; k < n; ++k) {
            printf("%d ", a[k]);
        }
        printf("\n");
    }
}

int main() {
    int array[] = {5, 2, 8, 1, 9, 7};
    int i, count;
    count = sizeof(array) / sizeof(int);
    //count = array의 갯수를 구하려는 변수 sizeof는 크기 구하는 함수
    //array에 int가 있어서 sizeof(int)로 int크기로 나눔 array에 int가 6개 있으니 6이 나옴
    Selection_Sort(array, count);
    printf("정렬 후 데이터 :");
    for (i = 0; i < count; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}