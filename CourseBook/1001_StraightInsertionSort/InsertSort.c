//
// Created by maicaoboy on 2023/10/15.
//

#include "SqList.h"

void InsertSort(SqLIst *L) {
    int j;
    for(int i = 2; i <= (*L).length; i++) {
        if((*L).data[i] < (*L).data[i-1]) {
            (*L).data[0] = (*L).data[i];
            (*L).data[i] = (*L).data[i - 1];
            for(j = i - 2; (*L).data[0] < (*L).data[j]; j--) {
                (*L).data[j+1] = (*L).data[j];
            }
            (*L).data[j+1] = (*L).data[0];
        }
    }
}