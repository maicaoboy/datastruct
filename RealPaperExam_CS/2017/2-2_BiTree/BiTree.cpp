//
// Created by maicaoboy on 2023/11/28.
//
#include "stdio.h"
#include "stdlib.h"

#define ElemType int

typedef struct BitNode {
    ElemType data;
    BitNode *firstChild, *nextSibling;
}BitNode, *BiTree;

//算法思想:先计算根节点的度,在计算根节点度的过程中递归计算根节点子节点的度,再取最大值即可得到最大的度
int maxDegree(BiTree T) {
    if(T == NULL) {
        return 0;
    }

    //计算当前节点的度
    int count = 0;
    int max = 0;
    int degree = 0;
    BitNode *ptr = T->firstChild;
    while(ptr != NULL) {
        count++;
        degree = maxDegree(ptr);
        if(degree > max) {
            max = degree;
        }
        ptr = ptr->nextSibling;
    }
    if(count > max) {
        max = count;
    }

    return max;
}

//打印树
void printTree(BiTree T) {
    if(T == NULL) {
        return;
    }
    printf("%d ", T->data);
    printTree(T->firstChild);
    printTree(T->nextSibling);
}

int main() {
    //建立一棵最大度为5的以孩子兄弟链表表示的树
    BiTree T = (BiTree) malloc(sizeof(BitNode));
    T->data = 1;
    T->firstChild = NULL;
    T->nextSibling = NULL;

    BitNode *ptr = NULL;
    BitNode *node = (BitNode *) malloc(sizeof(BitNode));
    node->data = 2;
    node->firstChild = NULL;
    node->nextSibling = NULL;
    T->firstChild = node;
    for (int i = 3; i < 5; ++i) {
        ptr = (BitNode *) malloc(sizeof(BitNode));
        ptr->data = i;
        ptr->firstChild = NULL;
        ptr->nextSibling = NULL;

        node->nextSibling = ptr;
        node = ptr;
    }


    node = (BitNode *) malloc(sizeof(BitNode));
    node->data = 5;
    node->firstChild = NULL;
    node->nextSibling = NULL;
    T->firstChild->firstChild = node;
    for (int i = 6; i < 7; ++i) {
        ptr = (BitNode *) malloc(sizeof(BitNode));
        ptr->data = i;
        ptr->firstChild = NULL;
        ptr->nextSibling = NULL;

        node->nextSibling = ptr;
        node = ptr;
    }

    node = (BitNode *) malloc(sizeof(BitNode));
    node->data = 7;
    node->firstChild = NULL;
    node->nextSibling = NULL;
    T->firstChild->nextSibling->nextSibling->firstChild = node;
    for (int i = 8; i < 11; ++i) {
        ptr = (BitNode *) malloc(sizeof(BitNode));
        ptr->data = i;
        ptr->firstChild = NULL;
        ptr->nextSibling = NULL;

        node->nextSibling = ptr;
        node = ptr;
    }


    //以上建树在onenote
    //孩子兄弟先序遍历:1 2 5 6 3 4 7 8 9 10
    //孩子兄弟中序遍历:5 6 2 3 7 8 9 10 4 1

    printTree(T);

    int degree = maxDegree(T);

    printf("\n最大的度为: %d\n", degree);

}



