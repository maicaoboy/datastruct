//
// Created by maicaoboy on 2023/12/9.
//
#include "stdio.h"
#include "stdlib.h"

typedef int ElemType;

typedef struct BitNode {
    ElemType data;
    struct BitNode *lchild, *rchild;
}BitNode, *BiTree;



/**
* 已知二叉树采用二叉链表存储结构，设计算法求二叉树中指定结点所在的层数
*/

/**
* 算法思想:使用先序遍历,每次递归将层数+1,若当前节点为带查找节点x,则返回当前递归的level层数,
 * 若当前节点不是x,则递归查找并返回左右子树中最大的level
*/

int findLevel(BiTree T, ElemType x, int level) {
    if(T == NULL) return 0;
    if(T->data == x) {
        return level;
    }
    int level1 = findLevel(T->lchild, x, level + 1);
    int level2 = findLevel(T->rchild, x, level + 1);
    return level1 > level2 ? level1 : level2;
}


int mian() {

}