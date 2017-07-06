//
// Created by young on 2017-07-06.
//

#include <stdio.h>

int main() {
    int i = 0;
    while (i < 5) {
        printf("%d\n", i++);
    }
    /*
     * 위 코드는
     * for(int i=0;i<5;i++) {
     *  printf("%d\n",i);
     * }
     * 이것과 똑같습니다
     * */
    return 0;
}