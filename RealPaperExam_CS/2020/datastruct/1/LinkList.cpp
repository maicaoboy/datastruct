//
// Created by maicaoboy on 2023/12/4.
//
#include "stdio.h"
#include "stdlib.h"

#define ElemType int
#define Status int
#define true 1
#define false 0

typedef struct LinkNode {
    ElemType data;
    LinkNode *next;
}LinkNode, *LinkList;


/**
* 一个带有表头结点的单链表，节点结构包括一个数据域 (data) 和一个指针域(next)。
 * 假设该链表只了一个头指针 (head)在不改变链表的前提下，
 * 请设计算法高效查找链表倒数第 m个位置(m为正整数)的节点并输出该节点的 data 值。
 * 查找成功返回 true，否则返回 false。
 * ------------------------------------------
 * 算法思想,使用快慢指针,快指针先走m步后快慢指针同时遍历链表,如果快指针到达表位说明查找成功
*/
Status findLastM(LinkList L, int m) {
    LinkNode *fast = L, *slow = L;
    for (int i = 0; i < m; ++i) {
        if(fast == NULL) {
            return false;
        }else {
            fast = fast->next;
        }
    }
    while(fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    if(slow == L) {
        printf("NULL");
        return false;
    }else {
        printf("%d", slow->data);
        return true;
    }
}

//打印链表
void printLinkList(LinkList L) {
    LinkNode *p = L->next;
    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    //建立带头结点的链表
    LinkList L = (LinkList)malloc(sizeof(LinkNode));
    L->next = NULL;
    LinkNode *p = L;
    for (int i = 0; i < 10; ++i) {
        LinkNode *node = (LinkNode*)malloc(sizeof(LinkNode));
        node->data = i;
        node->next = NULL;
        p->next = node;
        p = node;
    }
    printLinkList(L);
    findLastM(L, 3);
    return 0;
}





































