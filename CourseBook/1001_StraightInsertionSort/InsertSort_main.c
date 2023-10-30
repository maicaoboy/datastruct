//
// Created by maicaoboy on 2023/10/15.
//
#include "stdio.h"
#include "InsertSort.h"

int main() {
    SqLIst S;
    S.length = 10;

    S.data[1] = 6;
    S.data[2] = 12;
    S.data[3] = 1;
    S.data[4] = 4;
    S.data[5] = 8;
    S.data[6] = 1;
    S.data[7] = 7;
    S.data[8] = 56;
    S.data[9] = 78;
    S.data[10] = 3;

    InsertSort(&S);

    for(int i = 1; i <= S.length; i++) {
        printf("%d ", S.data[i]);
    }
}
