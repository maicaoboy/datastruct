//
// Created by maicaoboy on 2023/12/17.
//
#include "stdio.h"

int isNum(char *s) {
    if(*s > '0' && *s < '9') {
        return 1;
    }
    return 0;
}

int main() {
    char str[100];
    gets(str);

    int a[26] = {0};
    int length = 0;
    int num = 0;
    char *ptr = str;
    while(*ptr != '\0') {
        if(isNum(ptr)) {
            if(ptr != str && isNum(ptr - 1)) {
                num = num * 10 + *ptr - '0';
            } else {
                num = *ptr - '0';
            }
        }else {
            if(ptr != str && isNum(ptr - 1)) {
                a[length++] = num;
                num = 0;
            }
        }
        ptr++;
    }
    if(isNum(ptr - 1)) {
        a[length++] = num;
    }
    for (int i = 0; i < length; ++i){
        printf("%d ", a[i]);
    }

}