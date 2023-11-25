//
// Created by maicaoboy on 2023/11/25.
//
#include "stdio.h"
#include "stdlib.h"

#define ElemType int

typedef struct LinkNode {
    int data;
    LinkNode *next;
}LinkNode , *LinkList;


//算法思想: 由于链表有序,则重复元素在练表上连续,找到第一个e所在的节点,删除e后面所有值为e的节点即可
void deleteDuplicate(LinkList L, ElemType e) {
    LinkNode *pre = L;
    LinkNode *cur = L->next;

    while(cur != NULL) {
        cur = cur->next;
        if(cur->data == e) {
            pre = cur;
            cur = cur->next;
            while(cur!= NULL && cur->data == e) {
                pre->next = cur->next;
                free(cur);
                cur = pre->next;
            }
            break;
        }
    }
}

/**
 * 使用尾插法创建带头结点的单链表
 * @param L
 * @param list
 * @param listLength
 */
void createLinkList(LinkList &L, int list[], int listLength) {
    L = (LinkList) malloc(sizeof (LinkNode));
    L->next = NULL;
    LinkNode *cur = L;
    for (int i = 0; i < listLength; ++i) {
        LinkNode *node = (LinkNode*) malloc(sizeof (LinkNode));
        node->data = list[i];
        node->next = NULL;
        cur->next = node;
        cur = node;
    }
}


//打印带头结点的单链表
void printLinkList(LinkList L) {
    LinkNode *cur = L->next;
    while(cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    int list[] = {1,2,3,4,5,6,7,7,7,8};
    int listLength = 10;

    LinkList L = NULL;
    createLinkList(L, list, listLength);
    printLinkList(L);

    deleteDuplicate(L, 7);

    printLinkList(L);
}


