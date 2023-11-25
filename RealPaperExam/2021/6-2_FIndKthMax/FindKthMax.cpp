//
// Created by maicaoboy on 2023/11/25.
//
#include "stdio.h"
#include "stdlib.h"

#define ElemType int
typedef struct BitNode {
    ElemType data;
    BitNode *lchild, *rchild;
} BitNode, *BiTree;


int cnt = 0;
//中序遍历一棵二叉排序树可以获得升(降)序序列,因此以右根左的中序遍历去遍历一棵二叉排序树并找到第k个节点即可
int findKthMax_InOrder(BiTree T, int k, BitNode *&res) {
    if(T == NULL) {
        return 0;
    }
    if(findKthMax_InOrder(T->rchild, k, res)) {
        return 1;
    }
    cnt++;
    if(cnt == k) {
        res = T;
        return 1;
    }
    if(findKthMax_InOrder(T->lchild, k, res)) {
        return 1;
    }
}




//建立二叉排序树
void createBiTree(BiTree &T, ElemType list[], int listLength) {
    T = (BiTree) malloc(sizeof(BitNode));
    T->data = list[0];
    T->lchild = NULL;
    T->rchild = NULL;
    for (int i = 1; i < listLength; ++i) {
        BitNode *node = (BitNode *) malloc(sizeof(BitNode));
        node->data = list[i];
        node->lchild = NULL;
        node->rchild = NULL;
        BitNode *cur = T;
        while (cur != NULL) {
            if (node->data < cur->data) {
                if (cur->lchild == NULL) {
                    cur->lchild = node;
                    break;
                } else {
                    cur = cur->lchild;
                }
            } else {
                if (cur->rchild == NULL) {
                    cur->rchild = node;
                    break;
                } else {
                    cur = cur->rchild;
                }
            }
        }
    }
}


int main() {
    int list[10] = {5, 3, 7, 2, 4, 6, 8, 1, 9, 10};
    BiTree T = NULL;
    createBiTree(T, list, 10);
    BitNode *res = NULL;
    findKthMax_InOrder(T, 3, res);
    printf("%d\n", res->data);
}


