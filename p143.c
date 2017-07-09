//
// Created by young on 2017-07-09.
//

#include <stdio.h>

int main() {
    int i, su, hap = 0;
    float ave = 0.0f;

    for (i = 1; i < 4; i++) { //i =2 i =3  i=4
        printf("%d번?", i);
        scanf("%d", &su); //30
        hap = hap + su; //0 + 10 = 10 10+20 = 30 30+30 = 60
    }
    ave = (float) hap / 3;

    printf("합계 %d\n", hap);
    printf("평균 %4.lf\n", ave);
    return 0;
}