//
// Created by young on 2017-10-11.
//

#include <stdio.h>

bubble_Sort(int a[], int n) {
    int i, j, k, temp;
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) { //만약 앞에꺼가 뒤에꺼보다 크면 바꾸기
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        } //뒤에 모든 원소들을 비교
        printf("step %d : ", i);
        for (k = 0; k < n; k++) {
            printf("%d ", a[k]);
        }
        printf("\n");
    }
}

int main() {
    int array[] = {5, 2, 8, 1, 9, 7};
    int i, c;
    c = sizeof(array) / sizeof(int);
    bubble_Sort(array, c);
    printf("정렬 후 데이터 : ");
    for (int i = 0; i < 6; ++i) {
        printf("%d ", array[i]);
    }

    return 0;
}