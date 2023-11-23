//
// Created by maicaoboy on 2023/11/23.
//
#include "stdio.h"

void fun(int *list, int listLength) {
    int size = 0;       //已排序数组长度
    int curIndex = 0;   //未排序索引

    for (int i = 0; i < listLength; ++i) {
        int num = list[curIndex] * list[curIndex];
        int index = size - 1;
        while(index >= 0 && num <= list[index]) {
            list[index + 1] = list[index];
            index--;
        }
        list[index + 1] = num;
        curIndex++;
        size++;
    }
}

void printList(int *list, int listLength) {
    for (int i = 0; i < listLength; ++i) {
        printf("%d ", list[i]);
    }
    printf("\n");
}


int main() {
    int list[10] = {1,6,8,2,5,12,14,16,3,4};
    int listLength = 10;
    printList(list, listLength);
    fun(list, listLength);
    printList(list, listLength);
}