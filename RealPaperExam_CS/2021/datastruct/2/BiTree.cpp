//
// Created by maicaoboy on 2023/12/8.
//
#include "stdio.h"
#include "stdlib.h"

#define ElemType int

typedef struct BitNode {
    ElemType data;
    struct BitNode *lchild, *rchild;
    int lTag, rTag;         //1代表线索化
}BitNode, *BiTree;


void visit(BiTree T) {
    if(T !=  NULL) {
        printf("%d ", T->data);
    }
}

/**
 * Q2已知先序线索二叉树 T，编写算法完成对它的先序遍历。
 * 算法思想:    对于线序线索二叉树的一个节点,若其左子树没有线索化,则其直接后继为其左子树
 *            若其否则其直接后期为其右子树
 * @param T
 */

void traverseThreadTree(BiTree T) {
    if(T == NULL) {
        return;
    }
    BitNode *node = T;
    while (node != NULL) {
        visit(T);
        if(node->lTag == 0) {
            node = node->lchild;
        }else {
            node = node->rchild;
        }
    }
}
