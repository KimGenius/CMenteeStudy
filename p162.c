//
// Created by young on 2017-07-09.
//

#include <stdio.h>

int main() {
    int arr[2][3] = {
            {1, 2, 3},
            {4, 5, 6}
    };
    for (int i = 0; i < sizeof(arr) / 4; ++i) { // i = 0
        for (int j = 0; j < sizeof(arr[i])/4; ++j) { // j =1
            printf("%d", arr[i][j]); //1,2
        }
        printf("\n");
    }
    return 0;
}