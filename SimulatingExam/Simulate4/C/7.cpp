//
// Created by maicaoboy on 2023/12/23.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void REPLACE(char *olds, char *str1, char  *str2, char *newone) {
    char *ptr = olds;
    while(*ptr != '\0') {
        char *ptr1, *ptr2;
        for(ptr1 = ptr, ptr2 = str1; *ptr1 != '\0' && *ptr2 != '\0' && *ptr1 == *ptr2; ptr1++, ptr2++);
        if(*ptr2 == '\0') {
            int length = strlen(str2);
            *newone -= length;
            char *p = str2;
            while(*p != '\0') {
                *newone++ = *p++;
            }
        }else {
            *newone++ = *ptr;
        }
    }
    *newone = '\0';
}

int main() {
    printf("%2d%3d", 0, 21);
}