//
// Created by maicaoboy on 2023/12/17.
//
#include "stdio.h"
#include "stdlib.h"

typedef int ElemType;

typedef struct DuLNode {
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
} DuLNode, *DuLinkList;


int isDuiCheng(DuLinkList L) {
    DuLinkList ptr1 = L->next;
    DuLinkList ptr2 = L->prior;
    while(ptr1 != ptr2 && ptr1->next != ptr2) {
        if(ptr1->data != ptr2->data) {
            return 0;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->prior;
    }
    return 1;
}