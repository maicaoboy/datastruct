//
// Created by maicaoboy on 2023/12/14.
//
#include "stdlib.h"
#include "stdio.h"


typedef struct {
    int *list;
    int size, length;
}SqList;

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}


void adjust(SqList L) {
    if(L.length < 1) return;
    int *ou = &L.list[0];
    int *ji = &L.list[1];
    int *tail = L.list + L.length - 1;
    while(ou < tail && ji < tail) {
        while(ou < tail) {
            if(*ou % 2 == 1) {
                break;
            }
            ou += 2;
        }
        while(ji < tail) {
            if(*ji % 2 == 0) {
                break;
            }
            ji += 2;
        }
        if(ji < tail && ou < tail) {
            swap(ji, ou);
        }
    }
}

