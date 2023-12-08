//
// Created by maicaoboy on 2023/12/5.
//
#include <stdio.h>
int *p = NULL;
void f(int *p) {
    int static a = 10;
    *p += a;
}
int main(){
    int n,i;
    p=&n;
    for (i=1; i<= 5; i++) {
        if(0==i% 3) f(p);
    }
    printf("%d",n);
}
