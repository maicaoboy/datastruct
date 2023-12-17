//
// Created by maicaoboy on 2023/12/17.
//
#include "stdio.h"
#include "stdlib.h"

typedef int ElemType;
typedef struct BitNode {
    ElemType data;
    struct BitNode *lchild;
    struct BitNode *rchild;
} BitNode, *BiTree;

#define MAX_SIZE 100

int length = 0;
int maxLevel = 0;
BitNode *path[MAX_SIZE];

void findMaxLevel(BiTree T, int level) {
    if(T == NULL) {
        return;
    }
    if(level > maxLevel) {
        maxLevel = level;
    }
    findMaxLevel(T->lchild, level + 1);
    findMaxLevel(T->rchild, level + 1);
}

void printPath(BitNode *path[], int length) {
    for (int i = 0; i < length; ++i) {
        printf("%d ", path[i]->data);
    }
    printf("\n");
}


void preOrder(BiTree T, int level) {
    if(T == NULL) {
        return;
    }
    path[length++] = T;

    if(level == maxLevel) {
        printPath(path, length);
    }
    preOrder(T->lchild, level + 1);
    preOrder(T->rchild, level + 1);
    length--;
}

void insertBSTree(BiTree &T, ElemType x) {
    if(T == NULL) {
        T = (BiTree)malloc(sizeof(BitNode));
        T->data = x;
        T->lchild = NULL;
        T->rchild = NULL;
        return;
    }
    if(x < T->data) {
        insertBSTree(T->lchild, x);
    } else if(x > T->data) {
        insertBSTree(T->rchild, x);
    }
}

int main(){
    ElemType array[] = {5, 3, 7, 2, 4, 6, 8};
    BiTree T = NULL;
    for (int i = 0; i < 7; ++i) {
        insertBSTree(T, array[i]);
    }
    findMaxLevel(T, 1);
    preOrder(T, 1);
    return 0;
}
