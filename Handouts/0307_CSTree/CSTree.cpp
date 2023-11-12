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
    while(T != NULL) {
        visit(T);
        CSTNode *pCurChild = T->firstChild;
        while(NULL != pCurChild) {
            preOrderTraverse(pCurChild);
            pCurChild = pCurChild->nextSibling;
        }
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
        postOrderTraverse(T);
        pCurNode = pCurNode->nextSibling;
    }
    visit(T);
}


//计算一棵以孩子兄弟链表表示的树T的叶子节点个数
int countCSTreeLeaf(CSTree T) {
    if(T == NULL) {
        return 0;
    }
    int count = 0;
    if(T->firstChild == NULL){
        count++;
    }
    CSTNode *pCurNode = T->firstChild;
    while(pCurNode != NULL) {
        count += countCSTreeLeaf(pCurNode);
        pCurNode = pCurNode->nextSibling;
    }
    return count;
}

int leafSum = 0;
int getLeafsSum(CSTree T) {
    if(T == NULL) {
        return 0;
    }
    if(T->firstChild == NULL) {
        leafSum ++;
    }else {
        CSTNode *pCurNode = T->firstChild;
        while(pCurNode != NULL) {
            getLeafsSum(pCurNode);
            pCurNode = pCurNode->nextSibling;
        }
    }
}





































