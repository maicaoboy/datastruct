//
// Created by maicaoboy on 2023/11/27.
//
#include "stdio.h"
#include "stdlib.h"

#define ElemType int

typedef struct BitNode {
    ElemType data;
    BitNode *lchild, *rchild;
}BitNode, *BiTree;


int findAllAncestor_Pre(BiTree T, ElemType e) {
    if(T == NULL) {
        return 0;
    }
    if(T->data == e) {
        return 1;
    }
    if(findAllAncestor_Pre(T->lchild, e)) {
        printf("%d ", T->data);
        return 1;
    }
    if(findAllAncestor_Pre(T->rchild, e)) {
        printf("%d ", T->data);
        return 1;
    }
}

//打印二叉树
void printBiTree(BiTree T) {
    if(T == NULL) {
        return;
    }
    printf("%d ", T->data);
    printBiTree(T->lchild);
    printBiTree(T->rchild);
}

//往二叉排序树插入一个节点
void insertNode(BiTree &T, ElemType e) {
    if(T == NULL) {
        BitNode *node = (BitNode *) malloc(sizeof(BitNode));
        node->data = e;
        node->lchild = NULL;
        node->rchild = NULL;
        T = node;
        return;
    }else if(e < T->data) {
        insertNode(T->lchild, e);
    }else if(e > T->data) {
        insertNode(T->rchild, e);
    }
}



int main() {
    //建立排序二叉树
    ElemType list[] = {10, 3, 7, 2, 4, 6, 8,23,1,34,39,12};
    BiTree T = NULL;
    for (const auto &item: list) {
        insertNode(T, item);
    }
    printBiTree(T);
    printf("\n");
    findAllAncestor_Pre(T, 8);
}