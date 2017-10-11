//
// Created by young on 2017-09-05.
//

#include <stdio.h>
#include <unistd.h>

int main() {
    char a[18] = {'-', '-', '-', '-', '-', '-', '-', '뚝', '딱', '뚝', '딱', '-', '-', '-', '-', '-', '-', '-'};
    int i = 0;
    while(1){
        printf((const char *) a[0]);
        sleep(1000);
    }
    return 0;
}