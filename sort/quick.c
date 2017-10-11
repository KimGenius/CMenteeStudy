//
// Created by young on 2017-10-11.
//

#include <stdio.h>

int count = 0, m = 0;
int deep = 0;

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void quick_Sort(int a[], int left, int right) {
    deep++;
    printf("deep : %d\n",deep);
    int i, j, k, pivot;
    if (left < right) {
        i = left - 1;
        j = right;
        pivot = a[right];
        printf("pivot : %d\n",pivot);
        do {
            do { i++; } while (a[i] < pivot); //pivot 기준 큰거나 같은거 찾기
            do { j--; } while (j > left && a[j] > pivot);//pivot 기준 작은거 찾기
            if (i < j)swap(&a[i], &a[j]); //만약 작은거랑 큰거랑 순서 바뀌어있으면 바꿔주기

            printf("step %d : ", ++m);
            for (k = 0; k < count; ++k) {
                printf("%d ", a[k]);
            }
            printf("\n");
        } while (i < j);
        swap(&a[right], &a[i]); // pivot으로 썼던 값이랑 컸던 값이랑 바꿈
        printf("중간점검  ");
        for (k = 0; k < count; ++k) {
            printf("%d ", a[k]);
        }
        printf("\n");
        quick_Sort(a, left, i - 1);
        quick_Sort(a, i + 1, right);
    }
    deep--;
}

int main() {
    int array[] = {5, 2, 8, 1, 9, 7};
    int i;
    count = sizeof(array) / sizeof(int);
    quick_Sort(array, 0, count - 1); // -1을 하는이유 : pivot은 포함하면 안됨
    printf("\n");
    printf("정렬 후 데이터:");
    for (int i = 0; i < count; ++i) {
        printf("%d ", array[i]);
    }
    return 0;
}