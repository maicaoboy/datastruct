//
// Created by maicaoboy on 2023/11/25.
//
#include "stdlib.h"
#include "stdio.h"
#define Status int
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2

typedef struct BitNode {
    int data;
    BitNode *lchild, *rchild;
} BitNode, *BiTree;

typedef struct LevelNode {
    BitNode *data;
    int Level;
} LevelNode, *LevelList;




/* 宏定义 */
#define MAXQSIZE 1000   //最大队列长度

/* 循环队列元素类型定义 */
typedef LevelNode QElemType;

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



void findMaxInEveryLevel(BiTree T) {
    if(T == NULL) {
        return;
    }

    SqQueue Q;
    InitQueue(&Q);

    LevelList node = (LevelNode*) malloc(sizeof (LevelNode));
    node->data = T;
    node->Level = 1;
    int preLevel = 1;
    int curLevel = 1;
    int max = 0;

    EnQueue(&Q, *node);

    while(!QueueEmpty(Q)) {
        DeQueue(&Q, node);
        if(node->data->lchild) {
            LevelNode *ptr = (LevelNode*) malloc(sizeof (LevelNode));
            ptr->Level = node->Level + 1;
            ptr->data = node->data->lchild;
            EnQueue(&Q, *ptr);
        }

        if(node->data->rchild) {
            LevelNode *ptr = (LevelNode*) malloc(sizeof (LevelNode));
            ptr->Level = node->Level + 1;
            ptr->data = node->data->rchild;
            EnQueue(&Q, *ptr);
        }


        curLevel = node->Level;
        if(curLevel == preLevel) {
            if(node->data->data > max) {
                max = node->data->data;
            }
        }else {
            printf("%d 层最大值为 %d\n", preLevel, max);
            preLevel = curLevel;
            max = node->data->data;
        };
    }

}


//
void createBiTree(BiTree &T, int list[], int length) {
    T = (BiTree) malloc(sizeof(BitNode));
    T->data = list[0];
    T->lchild = NULL;
    T->rchild = NULL;
    for (int i = 1; i < length; ++i) {
        BitNode *node = (BitNode *) malloc(sizeof(BitNode));
        node->data = list[i];
        node->lchild = NULL;
        node->rchild = NULL;
        BitNode *cur = T;
        while (cur != NULL) {
            if (node->data < cur->data) {
                if (cur->lchild == NULL) {
                    cur->lchild = node;
                    break;
                } else {
                    cur = cur->lchild;
                }
            } else {
                if (cur->rchild == NULL) {
                    cur->rchild = node;
                    break;
                } else {
                    cur = cur->rchild;
                }
            }
        }
    }
}


int main() {
    int list[10] = {5, 3, 7, 2, 4, 6, 8, 1, 9, 10};
    BiTree T = NULL;
    createBiTree(T, list, 10);
    findMaxInEveryLevel(T);
    return 0;
}
