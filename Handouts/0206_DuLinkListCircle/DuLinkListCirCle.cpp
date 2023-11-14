//
// Created by xiang on 2023/11/2.
//
#include "stdlib.h"
#include "stdio.h"

typedef struct DuLinkNode {
    int data;
    DuLinkNode *next;
    DuLinkNode *prior;
}DuLinkNode, *DuLinkList;



void create_headInsert(DuLinkList &L, int array[], int length) {
    L = (DuLinkNode*)malloc(sizeof (DuLinkNode));
    L->next = L;
    L->prior = L;

    for(int i = 0; i < length; i++) {
        DuLinkNode *node = (DuLinkNode*)malloc(sizeof (DuLinkNode));
        node->data = array[i];
        node->next = L->next;
        node->next->prior = node;
        node->prior = L;
        L->next = node;
    }
}

void create_tailInsert(DuLinkList &L, int array[], int length) {
    L = (DuLinkNode*)malloc(sizeof (DuLinkNode));
    L->next = L;
    L->prior = L;


    for(int i = 0; i < length; i++) {
        DuLinkNode *node = (DuLinkNode*)malloc(sizeof (DuLinkNode));
        node->data = array[i];
        node->next = L;
        node->prior = L->prior;
        L->prior->next = node;
        L->prior = node;
    }
}

void freeLinkList(DuLinkList &L) {
    DuLinkNode *pre = L;
    DuLinkNode *cur = L->next;
    while(cur != L) {
        free(pre);
        pre = cur;
        cur = cur->next;
    }
    L = NULL;
}

void printList(DuLinkList L) {
    DuLinkNode *ptr = L->next;
    while(ptr != L) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void printList_prior(DuLinkList L) {
    DuLinkNode *ptr = L->prior;
    while(ptr != L) {
        printf("%d ", ptr->data);
        ptr = ptr->prior;
    }
}




/**
 * 例题31
 * 设以带头结点的双向循环链表表示的线性表为L=(a1,a2,a3...an),试写一时间复杂度为O(n)的算法
 * 将L改造为(a1,a3,....an,....a4,a2)
 * @param L
 */
void mixDuCircleLinkList(DuLinkList L) {
    DuLinkNode *cur = L->next;
    DuLinkNode *pre;
    L->next->prior = NULL;

    DuLinkNode *middle = L->prior;
    middle->prior->next = NULL;
    middle->prior = L;
    L->next = middle;

    while(cur) {
        pre = cur;
        cur = cur->next;
        pre->next = middle->next;
        pre->prior = middle;
        middle->next->prior = pre;
        middle->next = pre;


        if(cur) {
            pre = cur;
            cur = cur->next;
            pre->next = middle;
            pre->prior = middle->prior;
            middle->prior->next = pre;
            middle->prior = pre;
        }
    }



}































