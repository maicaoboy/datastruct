//
// Created by xiang on 2023/11/9.
//
#include "stdio.h"
#include "stdlib.h"
#define ElemType int

typedef struct BiThrNode {
    ElemType data;
    int lTag;
    int rTag;
    BiThrNode *lchild;
    BiThrNode *rchild;
}BiThrNode, *BiThrTree;

void visit(BiThrNode *node) {
    printf("%d ", node->data);
}

/**
 * 先序遍历
 * @param T
 */
void preOrderTraverse(BiThrTree T) {
    if(T == NULL) {
        return;
    }
    visit(T);
    preOrderTraverse(T->lchild);
    preOrderTraverse(T->rchild);
}


/**
 * 中序遍历
 * @param T
 */
void middleOrderTraverse(BiThrTree T) {
    if(T == NULL) {
        return;
    }
    middleOrderTraverse(T->lchild);
    visit(T);
    middleOrderTraverse(T->rchild);
}


/**
 * 后序遍历
 * @param T
 */
void postOrderTraverse(BiThrTree T) {
    if(T == NULL) {
        return;
    }
    postOrderTraverse(T->lchild);
    postOrderTraverse(T->rchild);
    visit(T);
}

void freeBiThrTree(BiThrTree &T) {
    if(T == NULL) {
        return;
    }
    freeBiThrTree(T->lchild);
    freeBiThrTree(T->rchild);
    free(T);
    T = NULL;
}

/**
 * 例题15 辅助函数
 * @param T
 * @param data
 */
void insertBiThrNode(BiThrTree &T, ElemType data) {
    if(T == NULL) {
        T = (BiThrNode*) malloc(sizeof (BiThrNode));
        T->data = data;
        T->lchild = NULL;
        T->rchild = NULL;
        T->lTag = 0;
        T->rTag = 0;
    }else if(T->data > data) {
        insertBiThrNode(T->lchild, data);
    }else if(T->data < data) {
        insertBiThrNode(T->rchild, data);
    }
}

/**
 * 例题15 设计算法构建一颗二叉排序树
 * @param T
 * @param array
 * @param length
 */
void createBiTree(BiThrTree &T, ElemType array[], int length) {
    for(int i = 0; i < length; i++) {
        insertBiThrNode(T, array[i]);
    }
}

/**
 * 算法24: 遍历先序线索二叉树
 * 遍历前序线索二叉树:
 * 前序线索二叉树的后继节点:1. lTag == 0, 则 lchild 为后继节点,否则 rchild 为后继节点
 * @param T
 */
void traversePreThrTree( BiThrTree T) {
    BiThrNode *node = T;
    while(node != NULL) {
        visit(node);
        if(node->lTag == 0) {
            node = node->lchild;
        }else {
            node = node->rchild;
        }
    }
}



/**
 * 例题23主函数 设计算法构建一棵先序线索二叉树
 */
BiThrNode *preNode = NULL;
void preOrderThreading(BiThrTree T) {
    if(T == NULL) {
        return;
    }
    if(T->lchild == NULL) {
        T->lchild = preNode;
        T->lTag = 1;
        if(preNode && preNode->rchild == NULL) {
            preNode->rchild = T;
            preNode->rTag = 1;
        }
    }
    preNode = T;
    if(0 == T->lTag) {
        preOrderThreading(T->lchild);
    }
    if(0 == T->rTag) {
        preOrderThreading(T->rchild);
    }
}

/**
 * 例题23: 设计算法构建一棵先序线索二叉树
 * @param T
 */
void preThreading(BiThrTree T) {
    preNode = NULL;
    preOrderThreading(T);
}

/**
 * 算法25主函数: 设计算法构建一颗中序线索二叉树
 * @param T
 */
void inOrderThreading(BiThrTree T) {
    if(NULL == T) {
        return;
    }
    if(T->lTag == 0) {
        inOrderThreading(T->lchild);
    }
    if(T->lchild == NULL) {
        T->lchild = preNode;
        T->lTag = 1;
    }
    if(preNode && NULL == preNode->rchild) {
        preNode->rchild = T;
        preNode->rTag = 1;
    }
    preNode = T;
    if(T->rTag == 0) {
        inOrderThreading(T->rchild);
    }
}


/**
 * 算法25: 设计算法构建一颗中序线索二叉树
 * @param T
 */
void inThreading(BiThrTree T) {
    preNode = NULL;
    inOrderThreading(T);
}


/**
 * 算法26: 遍历中序线索二叉树
 * 遍历中序线索二叉树:
 * 对于中序线索二叉树:如果 rTag == 1,则后继节点为 rchild, 否则后继节点为右子树左子树第一个节点
 * @param T
 */
void traverseInThrTree(BiThrTree T) {
    if(T == NULL) return;
    BiThrNode *node = T;
    while(node->lchild && node->lTag == 0) {
        node = node->lchild;
    }

    while(node) {
        visit(node);
        if(node->rTag == 1) {
            node = node->rchild;
        }else {
            node = node->rchild;
            while(node && node->lTag == 0) {
                node = node->lchild;
            }
        }
    }
}




































