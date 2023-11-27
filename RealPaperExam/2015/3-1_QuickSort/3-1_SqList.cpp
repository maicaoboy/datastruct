//
// Created by maicaoboy on 2023/11/27.
//

#include "stdio.h"
#include "stdlib.h"

#define ElemType int

struct SqList {
    ElemType *list;
    int length;
    int size;
};


int partition(SqList sqList, int begin, int end) {
    ElemType e = sqList.list[begin];
    while(begin < end) {
        while(begin < end && sqList.list[end] >= e) {
            end--;
        }
        if(begin < end) {
            sqList.list[begin] = sqList.list[end];
            begin++;
        }
        while(begin < end && sqList.list[begin] < e) {
            begin++;
        }
        if(begin < end){
            sqList.list[end] = sqList.list[begin];
            end--;
        }
    }
    sqList.list[begin] = e;
    return begin;
}

void quickSort(SqList sqList, int begin, int end) {
    if(begin >= end) {
        return;
    }
    int index = partition(sqList, begin, end);
    quickSort(sqList, begin, index - 1);
    quickSort(sqList, index + 1, end);
}


//打印SqList
void printSqList(SqList sqList) {
    for (int i = 0; i < sqList.length; ++i) {
        printf("%d ", sqList.list[i]);
    }
    printf("\n");
}



int main() {
    //测试快速排序
    SqList sqList;
    sqList.list = (ElemType *) malloc(10 * sizeof(ElemType));
    sqList.length = 10;
    sqList.size = 10;
    sqList.list[0] = 3;
    sqList.list[1] = 1;
    sqList.list[2] = 5;
    sqList.list[3] = 7;
    sqList.list[4] = 2;
    sqList.list[5] = 4;
    sqList.list[6] = 9;
    sqList.list[7] = 6;
    sqList.list[8] = 8;
    sqList.list[9] = 10;
    printSqList(sqList);
    quickSort(sqList, 0, sqList.length - 1);
    printSqList(sqList);



}


