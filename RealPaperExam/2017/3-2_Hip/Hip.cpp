//
// Created by maicaoboy on 2023/11/28.
//
#include "stdio.h"
#include "stdlib.h"


void adjust(int *hip, int n, int index) {
    int max = index;
    int left = index * 2;
    if(left <= n && hip[max] < hip[left]) {
        max = left;
    }
    int right = index * 2 + 1;
    if(right <= n && hip[max] < hip[right]) {
        max = right;
    }
    if(max == index) return;
    int temp = hip[index];
    hip[index] = hip[max];
    hip[max] = temp;
    adjust(hip, n, max);
}

void initHip(int *hip, int n) {//从1开始计数
    for (int i = n / 2; i >= 1; --i) {
        adjust(hip, n, i);
    }
}

void hipSort(int *hip, int n) {//从1开始计数
    for (int i = n / 2; i >= 1; --i) {
        adjust(hip, n, i);
    }
    for(int i = n; i >= 2; i--) {
        int temp = hip[i];
        hip[i] = hip[1];
        hip[1] = temp;
        adjust(hip, i - 1, 1);
    }
}

void printHip(int *hip, int size) {
    for (int i = 1; i < size; ++i) {
        printf("%d ", hip[i]);
    }
    printf("\n");
}


int main() {
    int hip[] = {0,22,56,34,12,34,2,7,34,98,23,12,45,83};
    int size = sizeof(hip) / sizeof(int);
    printHip(hip,size);
    initHip(hip, size - 1);
    printHip(hip,size);
}