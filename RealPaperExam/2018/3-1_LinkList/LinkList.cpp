//
// Created by maicaoboy on 2023/11/29.
//
#include "stdio.h"
#include "stdlib.h"

#define ELemType int

typedef struct LinkNode {
    ELemType e;
    LinkNode *next;
}LinkNode, *LinkList;

//{L1,L2,L3....Ln} -> {L1,Ln,L2,Ln-1....}
//算法思想: 首先反转链表1-n/2个节点作为L1, n/2 + 1个节点作为L2, 之后每次从L1和L2取一个节点头插法插入新链表即可;


void headInsert(LinkList &L, LinkNode *node) {
    if(L == NULL) {
        L = node;
        node->next = NULL;
    }else {
        node->next = L;
        L = node;
    }
}
void headInsertWithHead(LinkList L, LinkNode *node) {
    node->next = L->next;
    L->next = node;
}

void adjust(LinkList L, int n) {
    LinkList L1 = NULL;
    LinkList L2 = NULL;
    LinkNode *ptr = L->next;
    L->next = NULL;
    int cnt = n / 2;
    if(n % 2 == 1) {
        cnt++;
    }
    for (int i = 0; i < cnt; ++i) {       //反转前n/2个节点
        if(ptr != NULL) {
            LinkNode *next = ptr->next;
            headInsert(L1, ptr);
            ptr = next;
        }
    }
    L2 = ptr;

    while(L1 != NULL && L2 != NULL) {
        ptr = L1->next;
        headInsertWithHead(L, L1);
        L1 = ptr;

        ptr = L2->next;
        headInsertWithHead(L, L2);
        L2 = ptr;
    }

    if(L1 != NULL) {
        L1->next = L->next;
        L->next = L1;
        L1 = ptr;
    }
}

//print LinkList
void printLinkList(LinkList L) {
    LinkNode *cur = L->next;
    while (cur != NULL) {
        printf("%d ", cur->e);
        cur = cur->next;
    }
    printf("\n");
}


int main() {
    ELemType list[] = {9,8,7,6,5,4,3,2,1,0};
    int length = sizeof (list) / sizeof (int);

    LinkList L = (LinkList) malloc(sizeof (LinkNode));
    L->next = NULL;

    for (const auto &item: list) {
        LinkNode *node = (LinkNode*) malloc(sizeof (LinkNode));
        node->next = NULL;
        node->e = item;
        headInsertWithHead(L, node);
    }


    printLinkList(L);

    adjust(L, length);

    printLinkList(L);
}



















