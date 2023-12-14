//
// Created by maicaoboy on 2023/12/14.
//
#include "stdio.h"
#include "stdlib.h"

#define MAX_SIZE 100

typedef int ElemType;

typedef struct BitNode {
    ElemType data;
    struct BitNode *lchild, *rchild;
    struct BitNode *parent;
    int level;
}BitNode, *BiTree;


void preOrder(BiTree T, BitNode *parent) {
    if(T == NULL) return;
    T->parent = parent;
    preOrder(T->lchild, T);
    preOrder(T->rchild, T);
}


void setParent(BiTree T) {
    preOrder(T, NULL);
}

/**
 * 递归打印路径
 * @param T
 */
void printPath(BiTree T) {
    if(T == NULL) return;
    printPath(T->parent);
    printf("%d ", T->data);
}


void preOrder(BiTree T, BitNode *parent, ElemType value) {
    if(T == NULL) return;
    T->parent = parent;
    if(T->data == value) {
        printPath(T);
    }
    preOrder(T->lchild, T, value);
    preOrder(T->rchild, T, value);
}


/**
 * 求到value的所有路径
 * @param T
 * @param value
 */
void findParent(BiTree T, ElemType value) {
    preOrder(T, NULL, value);
}



int maxDepth = 0;
int levelCntList[MAX_SIZE] = {0};
void getWidth(BiTree T, int level) {
    if(T == NULL) return;
    if(level > maxDepth) {
        maxDepth = level;
    }
    levelCntList[level]++;
    getWidth(T->lchild, level + 1);
    getWidth(T->rchild, level + 1);
}

void getMaxWidth(BiTree T) {
    getWidth(T, 1);
    int maxWidth = 0;
    for (int i = 1; i <= maxDepth; ++i) {
        if(levelCntList[i] > maxWidth) {
            maxWidth = levelCntList[i];
        }
    }
    printf("maxWidth:%d\n", maxWidth);
}


//设计算法查找二叉树T中第k层中度为1的节点
int cnt = 0;
void preOrder_1(BiTree T, int level, int k) {
    if(T == NULL) return;
    if(level == k && (T->lchild == NULL ^ T->rchild == NULL)){
        cnt++;
    }
    preOrder_1(T->lchild, level + 1, k);
    preOrder_1(T->rchild, level + 1, k);
}


BitNode *nodeList[MAX_SIZE] = {NULL};
int nodeListLength = 0;
/**
 * 设计算法求距离根节点最远的所有叶子节点,并打印路径
 * @param T                 根节点
 * @param parent            父亲节点,初始值为NULL
 * @param level             当前层数
 */
void findfarestLeaf_Pre(BiTree T, BitNode *parent, int level) {
    if(T == NULL) return;
    T->parent = parent;
    T->level = level;
    if((T->lchild == NULL) ^ (T->rchild == NULL)) {
        if(nodeList[nodeListLength - 1]->level < level){
            nodeListLength = 0;
            nodeList[nodeListLength++] = T;
        }else if(nodeList[nodeListLength - 1]->level == level){
            nodeList[nodeListLength++] = T;
        }
    }
    findfarestLeaf_Pre(T->lchild, T, level + 1);
    findfarestLeaf_Pre(T->rchild, T, level + 1);
}

/**
 * 打印路径
 * @param nodeList              //对所有叶子节点打印路径
 * @param nodeListLength        //有最长路径的叶子节点个数
 */
void printPath(BitNode *nodeList[MAX_SIZE], int nodeListLength){
    for (int i = 0; i < nodeListLength; ++i){
        printPath(nodeList[nodeListLength]);
    }
}



void convertToPBiTree(BiTree T1, BiTree &T2, BitNode *parent) {
    if(T1 == NULL){
        T2 = NULL;
        return;
    }
    T2 = (BitNode*) malloc(sizeof (BitNode));
    T2->lchild = NULL;
    T2->rchild = NULL;
    T2->data = T1->data;
    T2->parent = parent;

    convertToPBiTree(T1->lchild, T2->lchild, T2);
    convertToPBiTree(T1->rchild, T2->rchild, T2);
}








