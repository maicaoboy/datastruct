//
// Created by maicaoboy on 2023/11/27.
//
#include "stdio.h"
#include "stdlib.h"
#define ELemType int

typedef struct BitNode {
    ELemType data;
    BitNode *lchild;
    BitNode *rchild;
}BitNode, *BiTree;

BitNode *preNode = NULL;

//算法思想,使用中序遍历(先右后左)获得降序序列,同时使用全局变量preNode记录上一次访问节点,
// 若访问到value时preNode仍为初始值则value为最大时,否则preNode则为待查找的值
BitNode* findValue_inOrder(BiTree T, ELemType value) {
    if(T == NULL) {
        return NULL;
    }

    BitNode *node = findValue_inOrder(T->rchild, value);
    if(node != NULL) {
        return node;
    }

    if(value >= T->data) {
        if(preNode == NULL) {
            return NULL;
        }else {
            return preNode;
        }
    }
    preNode = T;

    node = findValue_inOrder(T->lchild, value);
    return node;
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
    BitNode *node = findValue_inOrder(T, 2);
    if(node == NULL) {
        printf("Not Found!\n");
    }else {
        printf("%d\n", node->data);
    }
    return 0;
}