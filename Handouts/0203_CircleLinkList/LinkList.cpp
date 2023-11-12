//
// Created by maicaoboy on 2023/10/29.
//
#include "stdlib.h"
#include "stdio.h"

typedef struct LinkNode {
    int data;
    LinkNode * next;
} LinkNode, *LinkList;


/**
 * 输出循环单链表
 * @param L
 */
void printLinkList(LinkList L) {
    LinkNode *ptr = L->next;

    while(ptr != L) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

/**
 * 释放链表
 * @param L
 */
void freeLinkList(LinkList &L) {
    LinkNode *ptr = L->next;
    LinkNode *node = L->next;

    while(ptr != L) {
        node = ptr;
        ptr = ptr->next;
        free(node);
    }

    free(L);

    L = NULL;
}
/**
 * 例题:21
 * 建立带头结点的的循环单链表(头插法)
 * @param L             建立的链表
 * @param array         链表数据
 * @param length        数据个数
 */
void createCircleList_headInsert(LinkList &L, int array[], int length) {
    L = (LinkNode*)malloc(sizeof (LinkNode));
    L->next = L;

    for(int i = 0; i < length; i++) {
        LinkNode *node = (LinkNode*) malloc(sizeof(LinkNode));
        node->data = array[i];

        node->next = L->next;
        L->next = node;
    }
}


/**
 * 例题21_1
 * 建立带头结点的的循环单链表(尾插法)
 * @param L             建立的链表
 * @param array         链表数据
 * @param length        数据个数
 */
void createCircleList_tailInsert(LinkList &L, int array[], int length) {
    L = (LinkNode*)malloc(sizeof (LinkNode));
    L->next = L;
    LinkNode *tail = L;

    for(int i = 0; i < length; i++) {
        LinkNode *node = (LinkNode*) malloc(sizeof(LinkNode));
        node->data = array[i];

        node->next = tail->next;
        tail->next = node;
        tail = node;
    }
}



/**
 * 例题22
 * 设计一个算法,将一个带头节点的循环单链表中的所有节点的链接方向逆转
 * @param L
 */
void reverse(LinkList L) {
    LinkNode *pre = L;
    LinkNode *cur = L->next;
    LinkNode *next;

    while(cur != L) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    cur->next = pre;
}



/**
 * 例题23
 * 设计一个算法将一个不带头结点的循环单链表左移k个节点
 * @param L
 * @param k
 */
void leftMoveKStep(LinkList &L, int k) {
    for(int i = 0; i < k; i++) {
        L = L->next;
    }
}


/**
 * 例题24
 * 设计算法将循环链表中节点p的直接前驱删除(假设不带头结点)
 * @param p
 */
void removeBefore(LinkNode *p) {
    LinkNode *pre = p;
    LinkNode *cur = p->next;

    while(cur->next != p) {
        pre = cur;
        cur = cur->next;
    }
    pre->next = cur->next;
    free(cur);
}



LinkNode* getPreOfIth(LinkList L, int i) {
    for(int j = 0; j < i - 1; j++) {
        L = L->next;
    }
    return L;
}


/**
 * 例题26:已知L为一个单链表的头节点,设计算法将表中从i号结点到m号节点构成一个逆置的循环链表
 * @param L         原链表
 * @param L1        逆置后的链表
 * @param i
 * @param m
 */
void reverseIthToMth(LinkList L, LinkList &L1, int i, int m){
    LinkNode *cur;
    LinkNode *node;
    LinkNode *preI;
    LinkNode *preM;
    LinkNode *I;
    LinkNode *M;

    preI = getPreOfIth(L, i);
    preM = getPreOfIth(L,m);
    I = preI->next;
    M = preM->next;
    preI->next = M->next;
    M->next = NULL;



    L1 = (LinkNode*) malloc(sizeof (LinkNode));
    L1->next = L1;
    cur = I;
    while(cur!=NULL) {
        node = cur;
        cur = cur->next;
        node->next = L1->next;
        L1->next = node;
    }
}




/**
 * 例题27
 * 已知La和Lb分别为两个循环单链表的头指针节点,m和n分别为La和Lb中数据节点的个数,
 * 设计时间复杂度最小的算法将两个链表合并成一个带头的循环单链表
 * @param La
 * @param Lb
 */
void merge(LinkList &La, LinkList &Lb) {
    LinkNode *tailA = La;
    LinkNode *tailB = Lb;

    while(tailA ->next != La) {
        tailA = tailA->next;
    }

    while(tailB ->next != Lb) {
        tailB = tailB->next;
    }

    tailA->next = Lb->next;
    tailB->next = La;

    free(Lb);
    Lb = NULL;
}


/**
 * 已知La和Lb分别为两个循环单链表的头指针节点,m和n分别为La和Lb中数据节点的个数,
 * 设计时间复杂度最小的算法将两个链表合并成一个带头的循环单链表
 * @param La
 * @param Lb
 * @param m
 * @param n
 */
void merge_better(LinkList &La, LinkList &Lb, int m, int n) {
    LinkNode *ptrA = La;
    LinkNode *ptrB = Lb;
    LinkNode *ptr;
    LinkNode *node;

    if(m > n) {//A链表长
        ptr = ptrA;
        ptrA = ptrB;
        ptrB = ptrA;
    }
    ptr = ptrB->next;

    while(ptr != ptrB) {
        node = ptr;
        ptr = ptr->next;
        node->next = ptrA->next;
        ptrA->next = node;
    }

    free(Lb);

}

//创建尾指针指针指向的循环单链表
/**
 * 例题21_1
 * 建立带头结点的的循环单链表(尾插法)
 * @param L             建立的链表
 * @param array         链表数据
 * @param length        数据个数
 */
void createCircleList_tailInsert_ToTail(LinkList &L, int array[], int length) {
    L = (LinkNode*)malloc(sizeof (LinkNode));
    L->next = L;
    LinkNode *tail = L;

    for(int i = 0; i < length; i++) {
        LinkNode *node = (LinkNode*) malloc(sizeof(LinkNode));
        node->data = array[i];

        node->next = tail->next;
        tail->next = node;
        tail = node;
    }
    L = tail;
}



/**
 * 例题29
 * 请设计一种存储结构来存储带头节点的循环单链表La和Lb,使得两链表合并时效率尽可能高
 * 使用记录尾节点的循环单链表
 * @param La
 * @param Lb
 */
void combineCircleLinkList(LinkList &La, LinkList &Lb) {
    LinkNode *headA = La->next;
    LinkNode *headB = Lb->next;

    La->next = headB->next;
    Lb->next = headA;

    La = Lb;

    free(headB);
}















































