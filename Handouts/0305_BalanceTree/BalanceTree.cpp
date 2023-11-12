//
// Created by xiang on 2023/11/9.
//
#include "stdio.h"
#include "stdlib.h"
#define ElemType int

typedef struct BSTNode {
    ElemType data;
    int bf;
    BSTNode *lchild;
    BSTNode *rchild;
}BSTNode, *BSTree;

void visit(BSTNode *node) {
    printf("%d ", node->data);
}

/**
 * 先序遍历
 * @param T
 */
void preOrderTraverse(BSTree T) {
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
void middleOrderTraverse(BSTree T) {
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
void postOrderTraverse(BSTree T) {
    if(T == NULL) {
        return;
    }
    postOrderTraverse(T->lchild);
    postOrderTraverse(T->rchild);
    visit(T);
}

void freeBSTree(BSTree &T) {
    if(T == NULL) {
        return;
    }
    freeBSTree(T->lchild);
    freeBSTree(T->rchild);
    free(T);
    T = NULL;
}

int getHeight(BSTree T) {
    if(T == NULL) {
        return 0;
    }
    int left = getHeight(T->lchild);
    int right = getHeight(T->rchild);
    return left > right ? left + 1 : right + 1;
}

/**
 * 处理LL插入导致的失衡
 * @param T
 */
void LLRotation(BSTNode *&T) {
    BSTNode *node = T->lchild;
    T->lchild = node->rchild;
    node->rchild = T;
    T = node;
}


/**
 * 处理RR插入导致的失衡
 * @param T
 */
void RRRotation(BSTNode *&T) {
    BSTNode *node = T->rchild;
    T->rchild = node->lchild;
    node->lchild = T;
    T = node;
}

/**
 * 向AVL数中插入x
 * @param T
 * @param x
 */
void insertBTree(BSTree &T, int x) {
    if(T == NULL) {
        T = (BSTNode*) malloc(sizeof (BSTNode));
        T->lchild = NULL;
        T->rchild = NULL;
        T->bf = 0;
        T->data = x;
    }else if(x < T->data) {
        insertBTree(T->lchild, x);
        int left = getHeight(T->lchild);
        int right = getHeight(T->rchild);
        if((left - right) >  1) {//L
            if(x < T->lchild->data) {//情况LL
                LLRotation(T);
            }else if(x > T->lchild->data) {//情况LR
                RRRotation(T->lchild);
                LLRotation(T);
            }
        }
    }else if(x > T->data) {
        insertBTree(T->rchild, x);
        int left = getHeight(T->lchild);
        int right = getHeight(T->rchild);
        if((right - left) >  1) {//R
            if(x > T->rchild->data) {//情况RR
                RRRotation(T);
            }else if(x < T->rchild->data) {//情况RL
                LLRotation(T->rchild);
                RRRotation(T);
            }
        }
    }
}


/**
 * 建立AVL树
 * @param T
 * @param array
 * @param length
 */
void createBalanceTree(BSTree &T, ElemType array[], int length) {
    for(int i = 0; i < length; i++) {
        insertBTree(T, array[i]);
    }
}


/**
 * 例题15 辅助函数
 * @param T
 * @param data
 */
void insertBSTNode(BSTree &T, ElemType data) {
    if(T == NULL) {
        T = (BSTNode*) malloc(sizeof (BSTNode));
        T->data = data;
        T->lchild = NULL;
        T->rchild = NULL;
    }else if(T->data > data) {
        insertBSTNode(T->lchild, data);
    }else if(T->data < data) {
        insertBSTNode(T->rchild, data);
    }
}

/**
 * 例题15 设计算法构建一颗二叉排序树
 * @param T
 * @param array
 * @param length
 */
void createBSTree(BSTree &T, ElemType array[], int length) {
    for(int i = 0; i < length; i++) {
        insertBSTNode(T, array[i]);
    }
}



/**
 * 例题21: 计算二叉树中每个节点的平衡因子,同时返回二叉树中不平衡的节点个数
 * @param T
 * @param count
 * @return
 */
int calculateBF(BSTree T, int &count) {
    if(T == NULL) {
        return 0;
    }
    int left = getHeight(T->lchild);
    int right = getHeight(T->rchild);
    T->bf = left - right;
    if(left - right > 1 || right - left > 1) {
        count += 1;
    }
    calculateBF(T->lchild, count);
    calculateBF(T->rchild, count);
    return count;
}


//假设一颗平衡二叉树每个节点都标注了平衡因子,设计一个算法求平衡二叉树的高度
int countHeightWithBF(BSTree T) {
    if(T == NULL) {
        return 0;
    }

    return T->bf < 0 ? countHeightWithBF(T->lchild) - T->bf + 1 : countHeightWithBF(T->rchild) + T->bf + 1;
}



