//
// Created by maicaoboy on 2023/11/23.
//
#include "stdlib.h"
#include "stdio.h"

typedef struct LinkNode {
    int data;
    LinkNode *next;
}LinkNode, *LinkList;


/**
 * 3-1:给定循环带头节点的单链表L,试编写算法删除循环单链表L中倒数的第i个结点
 * 算法思想: 使用快慢指针,快指针比满指针先走i步,当快指针走到最后一个节点时,慢指针恰好位于倒数第i个指针的前驱节点,此时删除慢指针后驱节点即可
 * @param L
 * @param i
 */
void deleteLastI(LinkList L, int i) {
    LinkNode *fast = L;
    LinkNode *slow = L;
    for (int k = 0; k < i; ++k) {
        fast = fast->next;
    }
    while(fast->next != L) {
        slow = slow->next;
        fast = fast->next;
    }
    LinkNode *node = slow->next;
    slow->next = node->next;
    free(node);
}


//输出一个循环单链表
void printLinkList(LinkList L) {
    LinkNode *cur = L->next;
    while(cur != L) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    int list[10] = {1,2,3,4,5,6,7,8,9,10};
    LinkList L = (LinkList) malloc(sizeof (LinkNode));
    L->next = L;
    LinkNode *cur = L;
    for (int i = 0; i < 10; ++i) {
        LinkNode *node = (LinkNode*) malloc(sizeof (LinkNode));
        node->data = list[i];
        node->next = cur->next;
        cur->next = node;
        cur = node;
    }
    printLinkList(L);
    deleteLastI(L, 3);
    printLinkList(L);

}


