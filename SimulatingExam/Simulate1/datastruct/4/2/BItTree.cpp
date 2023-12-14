//
// Created by maicaoboy on 2023/12/12.
//
#include "stdio.h"
#include "stdlib.h"

typedef int ElemType;

typedef struct BitNode {
    ElemType data;
    struct BitNode *lchild;
    struct BitNode *rchild;
}BitNode, *BiTree;

int isBSTree(BiTree T) {
    if(T == NULL) return 1;
    int ret = 1;
    if(T->data > T->lchild->data && T->data < T->rchild->data) {
        ret = 0;
    }
    return ret && isBSTree(T->lchild) && isBSTree(T->rchild);
}



