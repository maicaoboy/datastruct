//
// Created by xiang on 2023/11/11.
//
#include "stdio.h"
#include "stdlib.h"
#define ElemType int

typedef struct CSTNode{
    ElemType data;
    CSTNode *firstChild;
    CSTNode *nextSibling;
} CSTNode, *CSTree;



void visit(CSTNode *node) {
    printf("%d ", node->data);
}


/**
 * 树的先根遍历算法:访问根节点,然后依次先根遍历每一棵子树
 * @param T
 */
void preOrderTraverse(CSTree T) {
    if(NULL == T) {
        return;
    }
    visit(T);
    CSTNode *pCurChild = T->firstChild;
    while(NULL != pCurChild) {
        preOrderTraverse(pCurChild);
        pCurChild = pCurChild->nextSibling;
    }
}

/**
 * 树的后根遍历算法:依次先根遍历每一棵子树,然后再访问根节点
 * @param T
 */
void postOrderTraverse(CSTree T) {
    if(T == NULL) {
        return;
    }
    CSTNode *pCurNode = T->firstChild;
    while(pCurNode != NULL) {
        postOrderTraverse(pCurNode);
        pCurNode = pCurNode->nextSibling;
    }
    visit(T);
}


/**
 * 例题27: 计算一棵以孩子兄弟链表表示的树T的叶子节点个数
 * @param T
 * @return
 */
int countCSTreeLeaf(CSTree T) {
    if(T == NULL) {
        return 0;
    }
    int count = 0;
    if(T->firstChild == NULL){
        count++;
    }else {
        CSTNode *pCurNode = T->firstChild;
        while(pCurNode != NULL) {
            count += countCSTreeLeaf(pCurNode);
            pCurNode = pCurNode->nextSibling;
        }
    }
    return count;
}

/**
 * 例题27: 计算一棵以孩子兄弟链表表示的树T的叶子节点个数
 */
int leafSum = 0;
int getLeafsSum(CSTree T) {
    if(T->firstChild == NULL) {
        leafSum ++;
    }else {
        CSTNode *pCurNode = T->firstChild;
        while(pCurNode != NULL) {
            getLeafsSum(pCurNode);
            pCurNode = pCurNode->nextSibling;
        }
    }
    return leafSum;
}


/**
 * 例题28:计算一棵以孩子兄弟链表表示的树T的度,该算法的时间复杂夫为O(n)
 * @param T
 * @return
 */
int degree(CSTree T) {
    if(T == NULL) {
        return 0;
    }
    if(T->firstChild == NULL) {
        return 1;
    }else {
        int countChild;
        int count = 0;
        int max = 0;
        CSTNode *node = T->firstChild;
        while(node != NULL) {
            count++;
            countChild = degree(node);
            if(countChild > max) {
                max = countChild;
            }
            node = node->nextSibling;
        }
        if(count > max) {
            max = count;
        }
        return max;
    }
}



//
















































































/**
 * 例题01
 * 给定二叉链表的先序遍历序列和中序遍历序列,构造一棵二叉链表表示的二叉树
 * @param preOrderArray                 先序遍历序列
 * @param preBegin                      先序遍历序列起点
 * @param preEnd                        先序遍历序列列终点
 * @param middleOrderArray              中序遍历序列
 * @param midBegin                      中序遍历序列起点
 * @param midEnd                        中序遍历序列终点
 * @return
 */
CSTNode * createBitTreePreMiddle(ElemType preOrderArray[], int preBegin, int preEnd,
                                ElemType middleOrderArray[], int midBegin, int midEnd) {
    if(preBegin > preEnd) {
        return NULL;
    }
    CSTNode *node = (CSTNode *) malloc(sizeof (CSTNode));
    node->data = preOrderArray[preBegin];

    int index = midBegin;
    int count = 0;
    while(middleOrderArray[index] != preOrderArray[preBegin]) {
        index++;
        count++;
    }

    node->firstChild = createBitTreePreMiddle(preOrderArray, preBegin + 1, preBegin + count,
                                          middleOrderArray, midBegin, index - 1);
    node->nextSibling = createBitTreePreMiddle(preOrderArray, preBegin + count + 1, preEnd,
                                          middleOrderArray, index + 1, midEnd);

    return node;
}

void freeCSTree(CSTree &T) {
    if(T == NULL) {
        return;
    }
    freeCSTree(T->firstChild);
    freeCSTree(T->nextSibling);
    free(T);
    T = NULL;
}





































