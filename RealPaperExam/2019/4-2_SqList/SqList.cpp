//
// Created by maicaoboy on 2023/11/29.
//
#include "stdio.h"
#include "stdlib.h"


#define ElemType int

struct SqList {
    ElemType *list;
    int length;         //顺序表当前长度
    int size;           //顺序表最大长度
};


void swap(ElemType *a, ElemType *b) {
    ElemType temp = *a;
    *a = *b;
    *b = temp;
}

//算法思想:使用left,right指针分别从表头表尾开始遍历,left指针找到值为x的元素时将left的值与right交换,之后right指针左移
void MoveX(SqList L, ElemType x) {
    if(L.length == 0) return;
    ElemType *left = L.list;
    ElemType *right = L.list + (L.length - 1);
    while(left != right) {
        if(*left == x) {
            swap(left, right);
            right--;
        }else {
            left++;
        }
    }
}

void printSqList(SqList L) {
    for (int i = 0; i < L.length; ++i){
        printf("%d ", L.list[i]);
    }
    printf("\n");
}

int main() {
    SqList L;
    L.size = 100;
    L.length = 15;
    L.list = (ElemType*) malloc(sizeof (ElemType) * 100);

    ElemType list[] = {4,1,2,3,4,5,4,6,7,8,9,10,11,12,34,4,67,79,9,423,1342344,4};
    L.length = sizeof (list) / sizeof (ElemType);

    for (int i = 0; i < L.length; ++i){
        L.list[i] = list[i];
    }

    printSqList(L);

    MoveX(L, 4);

    printSqList(L);

}




