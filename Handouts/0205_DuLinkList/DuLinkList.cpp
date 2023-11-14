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
    L->next = NULL;
    L->prior = NULL;

    for(int i = 0; i < length; i++) {
        DuLinkNode *node = (DuLinkNode*)malloc(sizeof (DuLinkNode));
        node->data = array[i];
        node->next = L->next;
        if(node->next) {
            node->next->prior = node;
        }
        node->prior = L;
        L->next = node;
    }
}

void create_tailInsert(DuLinkList &L, int array[], int length) {
    L = (DuLinkNode*)malloc(sizeof (DuLinkNode));
    L->next = NULL;
    L->prior = NULL;
    DuLinkNode *tail = L;


    for(int i = 0; i < length; i++) {
        DuLinkNode *node = (DuLinkNode*)malloc(sizeof (DuLinkNode));
        node->data = array[i];
        node->next = tail->next;
        node->prior = tail;
        tail->next = node;
        tail = node;
    }
}

void freeLinkList(DuLinkList &L) {
    DuLinkNode *ptr = L;
    while(ptr) {
        ptr = L->next;
        free(L);
        L = ptr;
    }
    L = NULL;
}

void printList(DuLinkList L) {
    DuLinkNode *ptr = L->next;
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void printList_prior(DuLinkList L) {
    DuLinkNode *ptr = L->prior;
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->prior;
    }
}



/**
 * 例题30
 * 设计一个算法,将带头接节点的双链表中的数据节点的原有顺序保存在每个节点的next域中,
 * 而prior域将所有节点按照值从小到大的顺序链接起来
 * @param L
 */
void sortDuLinkList(DuLinkList L) {
    DuLinkNode *pre;
    DuLinkNode *cur;
    DuLinkNode *ptr = L->next;

    while(ptr) {
        DuLinkNode *node = ptr;
        ptr = ptr->next;

        pre = L;
        cur = L->prior;

        while(cur && cur->data < node->data) {
            pre = cur;
            cur = cur->prior;
        }

        node->prior = cur;
        pre->prior = node;
    }
}

































