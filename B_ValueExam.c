//
// Created by young on 2017-07-04.
//

#include <stdio.h>

int main() {
    int int_a = 2147483647;
    float flo_a = 1.0;
    long lon_a = 2147483648L;
    char cha_a[4] = "asdf";
    char *str = "asdf";
    printf("%d\n", int_a);
    //%f type = %[integer length].[decimal length]f
    printf("%.2f\n", flo_a);
    printf("%ld\n", lon_a);
    printf("%s\n", cha_a);
    printf("%s\n", str);
    return 0;
}