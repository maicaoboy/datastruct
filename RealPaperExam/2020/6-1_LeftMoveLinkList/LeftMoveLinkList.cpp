//
// Created by maicaoboy on 2023/11/25.
//
#include "stdlib.h"
#include "stdio.h"

typedef struct LinkNode {
    int data;
    LinkNode * next;
} LinkNode, *LinkList;


//算法思想:让头节点移动到第K个元素的位置(假设链表L不带头节点)
void LeftMoveLinkList(LinkList &L, int k) {
    int i = k;
    while(i >= 0) {
        L = L->next;
        i--;
    }
}

//算法思想:让头节点移动到第K个元素的位置(假设链表L带头节点)
void LeftMoveLinkList_head(LinkList &L, int k) {
    LinkNode *pre = L;
    LinkNode *cur = L->next;
    LinkNode *ptr = L;

    //找到尾节点并移除头节点
    while(ptr->next != L) {
        ptr = ptr->next;
    }
    ptr->next = ptr->next->next;

    //找到第K个元素
    int i = k;
    while(cur != NULL && i > 0) {
        pre = cur;
        cur = cur->next;
        i--;
    }

    //将头节点插入到第K个元素的位置
    L->next = cur;
    pre->next = L;
}

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

//输出循环单链表(不带头节点)
void printLinkList_withoutHead(LinkList L) {
    LinkNode *ptr = L;

    printf("%d ", ptr->data);
    ptr = ptr->next;

    while(ptr != L) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

//创建带头结点的循环单链表(头插法)
void createCircleList_headInsert(LinkList &L,int array[], int length) {
    L = (LinkNode*)malloc(sizeof (LinkNode));
    L->next = L;

    for(int i = 0; i < length; i++) {
        LinkNode *node = (LinkNode*) malloc(sizeof(LinkNode));
        node->data = array[i];

        node->next = L->next;
        L->next = node;
    }

}

//创建不带头结点的循环单链表(头插法)
void createCircleList_headInsert_withoutHead(LinkList &L,int array[], int length) {
    L = (LinkNode*)malloc(sizeof (LinkNode));
    L->next = L;
    L->data = array[0];

    for(int i = 1; i < length; i++) {
        LinkNode *node = (LinkNode*) malloc(sizeof(LinkNode));
        node->data = array[i];

        node->next = L->next;
        L->next = node;
    }

}

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




int main() {
    LinkList L = NULL;
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    int length = sizeof(array) / sizeof(int);

    createCircleList_headInsert(L, array, length);
    printLinkList(L);
    printf("\n");

    LeftMoveLinkList_head(L, 3);
    printLinkList(L);
    printf("\n");

    freeLinkList(L);


    createCircleList_headInsert_withoutHead(L, array, length);
    printLinkList_withoutHead(L);
    printf("\n");

    LeftMoveLinkList(L, 3);
    printLinkList_withoutHead(L);
    printf("\n");

    return 0;
}