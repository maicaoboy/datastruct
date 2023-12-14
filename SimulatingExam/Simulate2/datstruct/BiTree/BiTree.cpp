//
// Created by maicaoboy on 2023/12/14.
//
#include "stdio.h"
#include "stdlib.h"

#define MAX_SIZE 100

typedef int ElemType;

typedef struct BitNode {
    ElemType data;
    struct BitNode *lchild, *rchild;
}BitNode, *BiTree;


void printPath(BitNode *path[MAX_SIZE], int length) {
    printf("path:");
    for (int i = 0; i < length; ++i){
        printf("%d ", path[i]->data);
    }
}

//算法思想:使用path数组记录路径,使用先序遍历二叉树,每次遇到value值的节点打印path数组即为路径
BitNode *path[MAX_SIZE];
int length = 0;

void preOrder(BiTree T, ElemType value) {
    if(T == NULL) return;
    if(T->data == value) {
        printPath(path, length);
    }
    path[length++] = T;
    preOrder(T->lchild, value);
    preOrder(T->rchild, value);
    length--;
}

