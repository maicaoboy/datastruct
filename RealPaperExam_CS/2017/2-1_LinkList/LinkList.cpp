//
// Created by maicaoboy on 2023/11/28.
//
#include "stdio.h"
#include "stdlib.h"

#define ElemType int

typedef struct LinkNode {
    ElemType data;
    LinkNode *next;
} LinkNode, *LinkList;

//算法思想:使用pre,cur指针遍历链表,当pre指针和cur指针的值相同时删除cur指针即可
void deleteDuplicate(LinkList L) {  //为带头结点的单链表
    LinkNode *pre = L;
    LinkNode *cur = L->next;

    if(cur ==  NULL){
        return ;
    }else {
        pre = cur;
        cur = cur->next;
    }

    while(cur != NULL){
        if(pre->data == cur->data) {
            pre->next = cur->next;
            free(cur);
            cur = pre->next;
        }else {
            pre = cur;
            cur = cur->next;
        }
    }
}


//print LinkList
void printLinkList(LinkList L) {
    LinkNode *cur = L->next;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    LinkList L = (LinkList) malloc(sizeof(LinkNode));
    L->next = NULL;
    ElemType list[] = {1, 2, 2, 3, 3, 3, 4, 5, 5, 6, 7,8,9,10,10};
    int length = sizeof(list) / sizeof(ElemType);
    for (int i = 0; i < length; ++i) {
        LinkNode *node = (LinkNode *) malloc(sizeof(LinkNode));
        node->data = list[i];
        node->next = NULL;
        LinkNode *cur = L;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = node;
    }
    printLinkList(L);

    deleteDuplicate(L);

    printLinkList(L);

    return 0;
}