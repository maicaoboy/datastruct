//
// Created by xiang on 2023/11/7.
//
#include "stdio.h"
#include "stdlib.h"
#include "../../Status/Status.h"

#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0

typedef int ElemType;

typedef struct BitNode {
    ElemType data;
    BitNode *lchild;
    BitNode *rchild;
}BitNode, *BitTree;

typedef struct BitNodeLevel {
    BitNode *node;
    int level;
} BitNodeLevel;

/* 宏定义 */
#define MAXQSIZE 1000   //最大队列长度


/* 循环队列元素类型定义 */
typedef BitNodeLevel * QElemType;

// 循环队列的顺序存储结构
typedef struct {
    QElemType* base;    // 动态分配存储空间
    int front;          // 头指针，若队列不空，指向队头元素
    int rear;           // 尾指针，若队列不空，指向队列尾元素的下一个位置
} SqQueue;

Status InitQueue(SqQueue* Q) {
    if(Q == NULL) {
        return ERROR;
    }

    (*Q).base = (QElemType*) malloc(MAXQSIZE * sizeof(QElemType));
    if(!(*Q).base) {
        exit(OVERFLOW);
    }

    (*Q).front = (*Q).rear = 0;

    return OK;
}

/*
 * 销毁(结构)
 *
 * 释放循环顺序队列所占内存。
 */
Status DestroyQueue(SqQueue* Q) {
    if(Q == NULL) {
        return ERROR;
    }

    if((*Q).base) {
        free((*Q).base);
    }

    (*Q).base = NULL;
    (*Q).front = (*Q).rear = 0;

    return ERROR;
}

/*
 * 置空(内容)
 *
 * 只是清理循环顺序队列中存储的数据，不释放顺序队列所占内存。
 */
Status ClearQueue(SqQueue* Q) {
    if(Q == NULL || (*Q).base == NULL) {
        return ERROR;
    }

    (*Q).front = (*Q).rear = 0;

    return OK;
}

/*
 * 判空
 *
 * 判断循环顺序队列中是否包含有效数据。
 *
 * 返回值：
 * TRUE : 循环顺序队列为空
 * FALSE: 循环顺序队列不为空
 */
Status QueueEmpty(SqQueue Q) {
    // 队列空的标志
    if(Q.front == Q.rear) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/*
 * 计数
 *
 * 返回循环顺序队列包含的有效元素的数量。
 */
int QueueLength(SqQueue Q) {
    if(Q.base == NULL) {
        return 0;
    }

    // 队列长度
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

/*
 * 取值
 *
 * 获取队头元素，将其存储到e中。
 * 如果可以找到，返回OK，否则，返回ERROR。
 */
Status GetHead(SqQueue Q, QElemType* e) {
    if(Q.base == NULL || Q.front == Q.rear) {
        return ERROR;
    }

    *e = Q.base[Q.front];

    return OK;
}

/*
 * 入队
 *
 * 将元素e添加到队列尾部。
 */
Status EnQueue(SqQueue* Q, QElemType e) {
    if(Q == NULL || (*Q).base == NULL) {
        return ERROR;
    }

    // 队列满的标志（会浪费一个空间来区分队列空和队列满）
    if(((*Q).rear + 1) % MAXQSIZE == (*Q).front) {
        return ERROR;
    }

    // 入队
    (*Q).base[(*Q).rear] = e;

    // 尾指针前进
    (*Q).rear = ((*Q).rear + 1) % MAXQSIZE;

    return OK;
}

/*
 * 出队
 *
 * 移除队列头部的元素，将其存储到e中。
 */
Status DeQueue(SqQueue* Q, QElemType* e) {
    if(Q == NULL || (*Q).base == NULL) {
        return ERROR;
    }

    // 队列空的标志
    if((*Q).front == (*Q).rear) {
        return ERROR;
    }

    // 出队
    *e = (*Q).base[(*Q).front];

    // 头指针前进
    (*Q).front = ((*Q).front + 1) % MAXQSIZE;

    return OK;
}

/*
 * 遍历
 *
 * 用visit函数访问队列Q
 */
Status QueueTraverse(SqQueue Q, void(Visit)(QElemType)) {
    int i;

    if(Q.base == NULL) {
        return ERROR;
    }

    for(i = Q.front; i != Q.rear; i = (i + 1) % MAXQSIZE) {
        Visit(Q.base[i]);
    }

    printf("\n");

    return OK;
}



void visit(BitNode *node) {
    printf("%d ", node->data);
}


/**
 * 先序遍历
 * @param T
 */
void preOrderTraverse(BitTree T) {
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
void middleOrderTraverse(BitTree T) {
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
void postOrderTraverse(BitTree T) {
    if(T == NULL) {
        return;
    }
    postOrderTraverse(T->lchild);
    postOrderTraverse(T->rchild);
    visit(T);
}

//void levelOrderTraverse(BitTree T) {
//    if(T == NULL) {
//        return;
//    }
//
//    SqQueue Q;
//    InitQueue(&Q);
//
//    EnQueue(&Q, T);
//
//    while(!QueueEmpty(Q)) {
//        BitNode *node;
//        DeQueue(&Q, &node);
//
//        visit(node);
//
//        if(node->lchild != NULL) {
//            EnQueue(&Q, node->lchild);
//        }
//
//        if(node->rchild != NULL) {
//            EnQueue(&Q, node->rchild);
//        }
//    }
//
//}

void freeBitTree(BitTree &T) {
    if(T == NULL) {
        return;
    }
    freeBitTree(T->lchild);
    freeBitTree(T->rchild);
    free(T);
    T = NULL;
}




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
BitNode* createBitTreePreMiddle(ElemType preOrderArray[], int preBegin, int preEnd,
                               ElemType middleOrderArray[], int midBegin, int midEnd) {
    if(preBegin > preEnd) {
        return NULL;
    }
    BitNode *node = (BitNode*) malloc(sizeof (BitNode));
    node->data = preOrderArray[preBegin];

    int index = midBegin;
    int count = 0;
    while(middleOrderArray[index] != preOrderArray[preBegin]) {
        index++;
        count++;
    }

    node->lchild = createBitTreePreMiddle(preOrderArray, preBegin + 1, preBegin + count,
                                          middleOrderArray, midBegin, index - 1);
    node->rchild = createBitTreePreMiddle(preOrderArray, preBegin + count + 1, preEnd,
                                          middleOrderArray, index + 1, midEnd);

    return node;
}




/**
 * 例题2
 * 给定二叉链表的层次遍历和中序遍历序列,构造一棵二叉链表表示的二叉树
 * @param levelOrderArray           先序遍历序列
 * @param levelBegin                先序遍历序列起点
 * @param levelEnd                  先序遍历序列列终点
 * @param middleOrderArray          中序遍历序列
 * @param midBegin                  中序遍历序列起点
 * @param midEnd                    中序遍历序列终点
 * @return
 */
BitNode* createBitTreeLevelMiddle(ElemType levelOrderArray[], int levelBegin, int levelEnd,
                                ElemType middleOrderArray[], int midBegin, int midEnd) {
    if(midBegin > midEnd) {
        return NULL;
    }

    BitNode *node = (BitNode*) malloc(sizeof (BitNode));
    node->data = levelOrderArray[levelBegin];

    int index = midBegin;
    while(middleOrderArray[index] != levelOrderArray[levelBegin]) {
        index++;
    }

    ElemType leftLevelOrderArray[MAX_SIZE];
    int leftSize = 0;
    ElemType rightLevelOrderArray[MAX_SIZE];
    int rightSize = 0;

    for(int i = levelBegin + 1; i <= levelEnd; i++) {
        int j;
        for(j = midBegin; j < index; j++) {
            if(levelOrderArray[i] == middleOrderArray[j]) {
                leftLevelOrderArray[leftSize++] = levelOrderArray[i];
                break;
            }
        }

        int k;
        for(k = index + 1; k <= midEnd; k++) {
            if(levelOrderArray[i] == middleOrderArray[k]) {
                rightLevelOrderArray[rightSize++] = levelOrderArray[i];
                break;
            }
        }
    }

    node->lchild = createBitTreeLevelMiddle(leftLevelOrderArray, 0, leftSize - 1,
                                            middleOrderArray, midBegin, index - 1);
    node->rchild = createBitTreeLevelMiddle(rightLevelOrderArray, 0, rightSize - 1,
                                            middleOrderArray, index + 1, midEnd);


    return node;

}


/**
 * 例题3: 求一个二叉树的节点个数
 * @param T
 * @return
 */
int countBitTree(BitTree T) {
    if(T == NULL) {
        return 0;
    }
    return 1 + countBitTree(T->lchild) + countBitTree(T->rchild);;
}



/**
 * 例题4:求一颗二叉树叶子结点的个数
 * @param T
 * @return
 */
int countLeaf(BitTree T) {
    if(T == NULL) {
        return 0;
    }
    if(T->lchild == NULL && T->rchild == NULL) {
        return 1;
    }
    return countLeaf(T->lchild) + countLeaf(T->rchild);
}




/**
 * 例题5: 求一颗二叉树中度为1的节点个数
 * @param T
 * @return
 */
int countNodeDegree1(BitTree T) {
    if(T == NULL){
        return 0;
    }
    int degree = 0;
    if((T->lchild == NULL && T->rchild != NULL) || (T->lchild != NULL && T->rchild == NULL)) {
        degree = 1;
    }
    return degree + countNodeDegree1(T->lchild) + countNodeDegree1(T->rchild);
}


/**
 * 例题6: 查找二叉树中值为x的结点,若存在,则返回存储位置,不存在,则返回空指针
 * @param T
 * @param x
 * @return
 */
BitNode* findNodeX(BitTree T, ElemType x) {
    if(T == NULL) {
        return NULL;
    }
    if(T->data == x) {
        return T;
    }
    BitNode *left = findNodeX(T->lchild, x);
    if(left) {
        return left;
    }
    return findNodeX(T->rchild, x);
}



/**
 * 例题7 求二叉树的高度
 * @param T
 * @return
 */
int heightBitTree(BitTree T) {
    if(T == NULL) {
        return 0;
    }
    int lHeight = heightBitTree(T->lchild);
    int rHeight = heightBitTree(T->rchild);
    return lHeight > rHeight ? (lHeight + 1) : (rHeight + 1);
}




/**
 * 例题8 求一颗二叉树中值为x的节点作为根节点的子树深度
 * @param T
 * @param x
 * @return
 */
int heightOfNodeX(BitTree T, int x) {
    BitNode *node = findNodeX(T, x);
    return heightBitTree(node);
}



/**
 * 例题9 交换一颗二叉树的左右子树
 * @param T
 * @return
 */
void swapChild(BitTree T) {
    if(T == NULL){
        return;
    }

    BitNode *temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;

    swapChild(T->lchild);
    swapChild(T->rchild);
}


/**
 * 例题10: 判断两棵树是否相似,相似返回TRUE, 不相似返回FALSE
 * @param T1
 * @param T2
 * @return
 */
int isSimilar(BitTree T1, BitTree T2) {
    if((T1 == NULL && T2 != NULL) || (T1 != NULL && T2 == NULL)) {
        return FALSE;
    }

    if(T1 == NULL && T2 == NULL) {
        return TRUE;
    }

    return isSimilar(T1->lchild, T2->lchild) && isSimilar(T1->rchild, T2->rchild);
}


/**
 * 例题 11 子函数
 * @param T
 * @param pTail
 */
void operate11(BitTree T, BitNode *&pTail)  {
    if(T == NULL) {
        return;
    }
    operate11(T->lchild, pTail);
    operate11(T->rchild, pTail);

    if(T->lchild == NULL && T->rchild == NULL) {
        pTail->rchild = T;
        T->lchild = pTail;
        pTail = T;
    }
}



/**
 * 例题11 设计算法利用叶子节点中的空指针域将所有叶子节点链接成一个带头节点的双链表
 * @param T
 * @return
 */
BitNode* createLeafToDuLinkList(BitTree T) {
    BitNode *node = (BitNode*) malloc(sizeof (BitNode));
    node->rchild = NULL;
    node->lchild = NULL;
    BitNode *pTail = node;
    operate11(T, pTail);
    return node;
}




/**
 * 例题13: 判断二叉树是否为完全二叉树
 * @param T
 * @return
 */
int isCompleteBitTree(BitTree T) {
//    SqQueue Q;
//    InitQueue(&Q);
//    EnQueue(&Q, T);
//
//
//    while(!QueueEmpty(Q)) {
//        BitNode *node;
//        DeQueue(&Q, &node);
//        if(node == NULL) {
//            break;
//        }
//        EnQueue(&Q, node->lchild);
//        EnQueue(&Q, node->rchild);
//    }
//
//    while(!QueueEmpty(Q)) {
//        BitNode *node;
//        DeQueue(&Q, &node);
//        if(node != NULL) {
//            return 0;
//        }
//    }
    return 1;
}


/**
 * 例题14: 求一颗二叉树的最大宽度
 * @param T
 * @return
 */
int maxWidth(BitTree T) {
    SqQueue Q;
    InitQueue(&Q);

    BitNodeLevel *levelNode = (BitNodeLevel*) malloc(sizeof (BitNodeLevel));
    levelNode->node = T;
    levelNode->level = 1;
    EnQueue(&Q, levelNode);

    int prelevel = 0;
    BitNodeLevel *preLevelNode = NULL;
    int max = 0;
    int count = 0;
    BitNodeLevel *node;

    while(!QueueEmpty(Q)) {
        DeQueue(&Q, &node);
        if(node->node == NULL) {
            continue;
        }
        if(node->level == prelevel) {
            count++;
        }else {
            if(count > max) {
                max = count;
            }
            count = 1;
            prelevel = node->level;
        }

        levelNode = (BitNodeLevel*) malloc(sizeof (BitNodeLevel));
        levelNode->node = node->node->lchild;
        levelNode->level = node->level + 1;
        EnQueue(&Q, levelNode);

        levelNode = (BitNodeLevel*) malloc(sizeof (BitNodeLevel));
        levelNode->node = node->node->rchild;
        levelNode->level = node->level + 1;
        EnQueue(&Q, levelNode);

        free(node);
        node = NULL;
    }

    return max;
}




































