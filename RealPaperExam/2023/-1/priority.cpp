//
// Created by maicaoboy on 2023/11/23.
//
#include "stdio.h"
#include "stdlib.h"

void fun(int *pl, int *s){
    int *t = (int *) malloc(2*sizeof (int));
    *t = *pl + *pl++;
    *s++ = *t;
    *(t+1) = *pl + *++pl;
    *s = *++t;
    s = t;
}

int main() {
    int a[3] = {1,2,3},b[2] = {0};
    fun(a, b);
    printf("%d %d\n", b[0], b[1]);
    int c = 1;
    c = c + c++;
    printf("%d \n", c);
}