//
// Created by maicaoboy on 2023/12/14.
//
#include "stdio.h"


int fun(int a, int b) {
    int k = 0, i = 0;
    while(i <= (b- a) / 3) {
        if(!(i % 2)) {
            printf("%c%c", i + a, 'a' - 'A');
        }else {
            ++k;
        }
        ++i;
    }
    return k;
}

#define N 4

void printMatrix(int a[N][N]) {
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int fun1(int a[N][N]) {
    printMatrix(a);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N - 1; ++j) {
            for (int k = j + 1; k < N; ++k) {
                if(!(i % 2) ? a[i][j] < a[i][k] : a[i][j] > a[i][k]) {
                    int t = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = t;
                    printMatrix(a);
                }
            }
        }
    }
}

int main() {
    int a = 0141;
    int b = '\x79';
    int c = fun(a, b);
    printf("%d",c);


    printf("\n");
    int m[][N] = {2,3,4,1,8,6,5,7,11,12,10,9,15,14,16,13};
    fun1(m);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d", m[i][j]);
        }
    }
}