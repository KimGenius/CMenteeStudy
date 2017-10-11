//
// Created by young on 2017-10-11.
//

#include <stdio.h>

int count = 0, m = 0;

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void quick_Sort(int a[], int left, int right) {
    int i, j, k, pivot;
    if (left < right) {
        i = left - 1;
        j = right;
        pivot = a[right];
        do {
            do { i++; } while (a[i] < pivot);
            do { j--; } while (j > left && a[j] > pivot);
            if (i < j)swap(&a[i], &a[j]);

            printf("step %d : ", ++m);
            for (k = 0; k < count; ++k) {
                printf("%d ", a[k]);
            }
            printf("\n");
        } while (i < j);
        swap(&a[right], &a[i]);
        printf("중간점검 : ");
        for (int i = 0; i < count; ++i) {
            printf("%d ", a[i]);
        }
        printf("left : %d, right : %d, i : %d", left, right, i);
        printf("\n");
        quick_Sort(a, left, i - 1);
        quick_Sort(a, i + 1, right);
    }
}

int main() {
    int array[] = {5, 2, 8, 1, 9, 7};
    int i;
    count = sizeof(array) / sizeof(int);
    quick_Sort(array, 0, count - 1);
    printf("\n");
    printf("정렬 후 데이터:");
    for (int i = 0; i < count; ++i) {
        printf("%d ", array[i]);
    }
    return 0;
}