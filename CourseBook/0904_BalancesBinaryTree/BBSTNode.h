//
// Created by maicaoboy on 2023/10/12.
//

#ifndef CLION_BBSTNODE_H
#define CLION_BBSTNODE_H

#define EQ(a, b) ((a) == (b))
#define LT(a, b) ((a) < (b))
#define LQ(a, b) ((a) <= (b))

#define LH 1
#define EH 0
#define RH -1

#include "Status.h"

typedef int KeyType;

/* 二叉树元素类型定义，这里假设其元素类型为char */
typedef struct {
    KeyType key;
}ElemType;

/* 二叉树结点定义 */
typedef struct BSTNode {
    ElemType data;              // 结点元素
    int bf;                     //节点的平衡因子
    struct BSTNode* lchild;     // 左孩子指针
    struct BSTNode* rchild;     // 右孩子指针
}BSTNode, *BSTree;


#endif //CLION_BBSTNODE_H
