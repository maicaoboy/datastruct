//
// Created by maicaoboy on 2023/12/7.
//
#include "stdio.h"
#include "stdlib.h"

#define ElemType int

typedef struct BitNode{
    ElemType data;
    struct BitNode *lchild;
    struct BitNode *rchild;
}BitNode, *BiTree;

/**
* 判断两棵树是否相似
 * 算法思想:使用先序遍历,判断每个节点是否相似(同时为NULL或者不为NULL即为相似),并且其左右子树相似即为相似
*/
int isSimilar(BiTree T1, BiTree T2) {
    if(T1 == NULL && T2 == NULL) return 1;
    if((T1 != NULL && T2 == NULL) || (T1 == NULL && T2 != NULL)) return 0;
//    int ret = 1;
//    if(isSimilar(T1->lchild, T2->lchild) == 0 || isSimilar(T1->rchild, T2->rchild) == 0) {
//        ret = 0;
//    }
//    return ret;
    return isSimilar(T1->lchild, T2->lchild) && isSimilar(T1->rchild, T2->rchild);
}