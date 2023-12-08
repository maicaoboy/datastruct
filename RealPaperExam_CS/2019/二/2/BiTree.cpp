//
// Created by maicaoboy on 2023/12/6.
//
#include "stdio.h"
#include "stdlib.h"


/**
* 假设二又树终止为x的结点不少于1个,采用二叉链表存储，编写算法，打印值为 X的结点的所有祖先。
*/


/**
 * 算法思想:使用后序遍历,若子树中存在x则打印当前节点
 */
#define ElemType int
typedef struct BitNode {
    ElemType data;
    BitNode *rchild, *lchild;
}BitNode, *BiTree;

int postOrder_X(BiTree T, ElemType x) {
    if(T == NULL) return 0;

    int ret = 0;
    if(postOrder_X(T->lchild, x)) {
        ret = 1;
    }
    if(postOrder_X(T->rchild,x)) {
        ret = 1;
    }
    if(ret) {
        printf("%d ", T->data);
    }
    return T->data == x || ret;
}

int main() {

}
