//
// Created by maicaoboy on 2023/11/23.
//
#include "stdio.h"
#include "stdlib.h"

typedef struct BiNode {
    int data;
    BiNode *lchild, *rchild;
}BiNode, *BiTree;


/**
 * 判断两棵树是否相似
 * 先序遍历,判断根是否相似,再递归判断左右子树是否相似
 * @param T1
 * @param T2
 * @return
 */
int isSimilar(BiTree T1, BiTree T2) {
    if(T1 == NULL && T2 == NULL) {
        return 1;
    }
    if((T1 == NULL && T2 != NULL) || (T1 != NULL && T2 == NULL)) {
        return 0;
    }
    return isSimilar(T1->lchild, T2->lchild) && isSimilar(T1->rchild, T2->rchild);
}

/**
 * 判断一棵树是否对称
 * 算法思想:将树T从根节点分为左右子树,从而比较子树根节点是否相似并递归比较两棵树的所有子树即可
 * @param T
 * @return
 */
int symmetryTree(BiTree T) {
    if(T == NULL) {
        return 1;
    }
    return isSimilar(T->lchild, T->rchild);
}

int main() {
    //建立一棵二叉树
    BiTree T = (BiTree) malloc(sizeof (BiNode));
    T->data = 1;
    T->lchild = (BiTree) malloc(sizeof (BiNode));
    T->lchild->data = 2;
    T->rchild = (BiTree) malloc(sizeof (BiNode));
    T->rchild->data = 2;
    T->lchild->lchild = (BiTree) malloc(sizeof (BiNode));
    T->lchild->lchild->data = 3;
    T->lchild->rchild = (BiTree) malloc(sizeof (BiNode));
    T->lchild->rchild->data = 4;
    T->rchild->lchild = (BiTree) malloc(sizeof (BiNode));
    T->rchild->lchild->data = 4;
    T->rchild->rchild = (BiTree) malloc(sizeof (BiNode));
    T->rchild->rchild->data = 3;
    T->lchild->lchild->lchild = NULL;
    T->lchild->lchild->rchild = NULL;
    T->lchild->rchild->lchild = NULL;
    T->lchild->rchild->rchild = NULL;
    T->rchild->lchild->lchild = NULL;
    T->rchild->lchild->rchild = NULL;
    T->rchild->rchild->lchild = NULL;
    T->rchild->rchild->rchild = NULL;


    printf("%d\n", symmetryTree(T));


    //建立一棵结构上非对称二叉树
    BiTree T2 = (BiTree) malloc(sizeof (BiNode));
    T2->data = 1;
    T2->lchild = (BiTree) malloc(sizeof (BiNode));
    T2->lchild->data = 2;
    T2->rchild = (BiTree) malloc(sizeof (BiNode));
    T2->rchild->data = 2;
    T2->lchild->lchild = (BiTree) malloc(sizeof (BiNode));
    T2->lchild->lchild->data = 3;
    T2->lchild->rchild = (BiTree) malloc(sizeof (BiNode));
    T2->lchild->rchild->data = 4;
    T2->rchild->lchild = (BiTree) malloc(sizeof (BiNode));
    T2->rchild->lchild->data = 5;
    T2->rchild->rchild = NULL;
    T2->lchild->lchild->lchild = NULL;
    T2->lchild->lchild->rchild = NULL;
    T2->lchild->rchild->lchild = NULL;
    T2->lchild->rchild->rchild = NULL;
    T2->rchild->lchild->lchild = NULL;
    T2->rchild->lchild->rchild = NULL;


    printf("%d\n", symmetryTree(T2));


}