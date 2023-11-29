//
// Created by maicaoboy on 2023/11/29.
//
#include "stdio.h"
#include "stdlib.h"

#define ELemType int

typedef struct BitNode {
    ELemType data;
    struct BitNode *lchild;
    struct BitNode *rchild;
}BitNode, *BiTree;

int findLevel(BiTree T, ELemType e, int level) {
    if(T == NULL) {
        return 0;
    }
    if(T->data == e) {
        return level;
    }
    int ret = findLevel(T->lchild, e, level +1);
    if(ret) {
        return ret;
    }
    ret = findLevel(T->rchild, e, level + 1);
    if(ret) {
        return ret;
    }
    return 0;
}

int findElemLevel(BiTree T, ELemType e) {
    return findLevel(T, e, 1);
}


//向排序二叉树中插入一个节点
void insertNode(BiTree &T, ELemType value) {
    if(T == NULL) {
        BitNode *node = (BitNode *) malloc(sizeof(BitNode));
        node->data = value;
        node->lchild = NULL;
        node->rchild = NULL;
        T = node;
        return;
    }else if(value < T->data) {
        insertNode(T->lchild, value);
    }else if(value > T->data) {
        insertNode(T->rchild, value);
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

int main() {
    BiTree T = NULL;
    int list[] = {5, 3, 7, 2, 4, 6, 8};
    int listLength = 7;
    for (int i = 0; i < listLength; ++i) {
        insertNode(T, list[i]);
    }
    printBiTree(T);
    printf("\n");

    ELemType e = 8;
    int level = findElemLevel(T, e);
    if(level) {
        printf("level of %d is %d\n", e, level);
    }else{
        printf("not found\n");
    }
}