//
// Created by maicaoboy on 2023/11/29.
//
#include "stdlib.h"
#include "stdio.h"

#define ElemType int

typedef struct BitNode {
    ElemType data;
    struct BitNode *lchild;
    struct BitNode *rchild;
}BitNode, *BiTree;

int max = 0;

//从根节点遍历,分别找出根节点T左右子树的最大距离再加起来就是最大路径
int maxPath(BiTree T, int len) {
    if(T == NULL) {
        return len;
    }
    int left = maxPath(T->lchild, len + 1);
    int right = maxPath(T->rchild, len + 1);
    return right >= left ? right : left;
}

int calculate(BiTree T) {
    if(T == NULL) return 0;
    int left = maxPath(T->lchild, 0);
    int right = maxPath(T->rchild, 0);
    int sum = right + left;
    max = sum > max ? sum : max;
    calculate(T->lchild);
    calculate(T->rchild);
    return max;
}


//向排序二叉树中插入一个节点
void insertNode(BiTree &T, ElemType value) {
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
    ElemType list[] = {5,3,20,2,4,10,30,7,8,9,31,32,33};
    int listLength = sizeof (list) / sizeof (ElemType);
    for (int i = 0; i < listLength; ++i) {
        insertNode(T, list[i]);
    }
    printBiTree(T);
    printf("\n");

    int distance = calculate(T);
    printf("最大距离为:%d \n", distance);
}



