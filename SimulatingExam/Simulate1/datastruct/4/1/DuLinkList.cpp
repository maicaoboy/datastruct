//
// Created by maicaoboy on 2023/12/12.
//

#include "stdio.h"
#include "stdlib.h"

typedef int ElemType;

typedef struct DuLinkNode {
    ElemType data;
    struct DuLinkNode *prior, *next;
}DuLinkNode, *DuLinkList;


void findSumX(DuLinkList L, int x) {
    DuLinkNode *head = L->next;
    DuLinkNode *tail = L;

    while(tail->next != NULL) {
        tail = tail->next;
    }

    int flag = 0;

    while(head != NULL && tail != NULL && head != tail) {
        if(head->data + tail->data == x) {
            printf("%d=%d+%d", x, head->data, tail->data);
            flag = 1;
            break;
        }else if(head->data + tail->data > x){
            tail = tail->prior;
        }else {
            head = head->next;
        }
    }
    if(!flag) {
        printf("No");
    }
}


void createDuLinkList(DuLinkList &L, int array[], int length) {
    L = (DuLinkList)malloc(sizeof(DuLinkNode));
    L->next = NULL;
    L->prior = NULL;

    DuLinkNode *tail = L;
    DuLinkNode *node = NULL;

    for (int i = 0; i < length; ++i) {
        node = (DuLinkNode *)malloc(sizeof(DuLinkNode));
        node->data = array[i];
        node->next = NULL;
        node->prior = tail;
        tail->next = node;
        tail = node;
    }
}

void freeDuLinkList(DuLinkList &L) {
    DuLinkNode *node = L;
    DuLinkNode *temp = NULL;
    while(node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
}


void printDuLinkList(DuLinkList L) {
    DuLinkNode *node = L->next;
    while(node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    DuLinkList L;
    DuLinkNode *node = NULL;
    int array[] = {1,2,3,4,5,6,7,8,9};
    int length = 9;
    int x = 7;

    createDuLinkList(L, array, length);
    printDuLinkList(L);
    findSumX(L, x);
    freeDuLinkList(L);
    return 0;
}