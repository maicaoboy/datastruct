//
// Created by maicaoboy on 2023/12/10.
//
#include "stdio.h"
#include "stdlib.h"

typedef int ElemType;

typedef struct BitNode {
    ElemType data;
    BitNode *lchild, *rchild;
}BitNode, *BiTree;


typedef struct {
    BitNode *node;
    int level;
}QElemType;

/**
 * 求二叉树的最大密度
 * 算法思想:使用队列,利用队列广度优先遍历,
 * 每次树的子节点入队需要对其层数标记为当前层数+1,之后统计相同层数最多节点即为最大密度
 * @param T
 * @return
 */
int MaxWidth(BiTree T) {
    if(T == NULL) return 0;
    Queue Q;
    QElemType *ptr = (QElemType*)malloc(sizeof(QElemType));;
    ptr->level = 1;
    ptr->node = T;
    EnQueue(&Q, ptr);
    int max = 0;
    int preLevel = 1;
    int count;
    QElemType e;
    while(!QueueEmpty(Q)) {
        DeQueue(&Q, &e);
        if(e.level != preLevel) {
            if(count > max) {
                max = count;
            }
        }else {
            count++;
        }
        if(e.node->lchild != NULL) {
            QElemType *ptr = (QElemType*)malloc(sizeof(QElemType));
            ptr->level = e.level + 1;
            ptr->node = e.node->lchild;
            EnQueue(&Q, ptr);
        }
        if(e.node->rchild != NULL) {
            QElemType *ptr = (QElemType*)malloc(sizeof(QElemType));
            ptr->level = e.level + 1;
            ptr->node = e.node->rchild;
            EnQueue(&Q, ptr);
        }
        preLevel = e.level;
    }
    if(count > max) {
        max = count;
    }

    return max;
}
