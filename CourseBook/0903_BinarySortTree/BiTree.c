/*=============================
 * 二叉树的二叉链表存储结构
 *
 * 包含算法: 6.1、6.2、6.3、6.4
 =============================*/

#include "BiTree.h"
#include "LinkQueue.h"  //**▲03 栈和队列**//
#include "SqStack.h"    //**▲03 栈和队列**//

/*
 * 初始化
 *
 * 构造空二叉树。
 */
Status InitBiTree(BiTree* T) {
    if(T == NULL) {
        return ERROR;
    }
    
    *T = NULL;
    
    return OK;
}

/*
 * 销毁
 *
 * 释放二叉树所占内存。
 *
 *【注】
 * 二叉树的二叉链表存储结构可以销毁，但是没必要销毁。
 * 因为二叉链表销毁后的状态与置空后的状态是一致的。
 */
Status DestroyBiTree(BiTree* T) {
    // 无需销毁，使用置空就可以
    return ERROR;
}

/*
 * 置空
 *
 * 清理二叉树中的数据，使其成为空树。
 */
Status ClearBiTree(BiTree* T) {
    if(T == NULL) {
        return ERROR;
    }

    // 在*T不为空时进行递归清理
    if(*T) {
        if((*T)->lchild!=NULL) {
            ClearBiTree(&((*T)->lchild));
        }

        if((*T)->rchild!=NULL) {
            ClearBiTree(&((*T)->rchild));
        }

        free(*T);
        *T = NULL;
    }

    return OK;
 }


