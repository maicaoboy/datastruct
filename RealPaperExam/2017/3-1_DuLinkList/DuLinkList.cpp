//
// Created by maicaoboy on 2023/11/28.
//
#include "stdio.h"
#include "stdlib.h"

typedef struct DuLNode {
    int data;
    int freq;
    struct DuLNode *lLink;
    struct DuLNode *rLink;
} DuLNode, *DuLinkList;


//算法思想:
DuLNode *Locate(DuLinkList L, int e) { //带头结点双向链表
    DuLNode *ptr = L->rLink;
    while (ptr != NULL) {
        if(ptr->data == e) {
            ptr->freq++;
            DuLNode *pre = ptr->lLink;
            while(pre != L && pre->freq < ptr->freq) {//查找ptr插入位置
                pre = pre->lLink;
            }
            if(pre->rLink != ptr) {         //需要移动
                //移除ptr节点
                if(ptr->rLink != NULL) {
                    ptr->rLink->lLink = ptr->lLink;
                }
                ptr->lLink->rLink = ptr->rLink;

                //插入ptr节点
                ptr->rLink = pre->rLink;
                ptr->lLink = pre;
                pre->rLink->lLink = ptr;
                pre->rLink = ptr;
            }
            return ptr;
        }
        ptr = ptr->rLink;
    }
    return ptr;
}

//print DuLinkList
void printDuLinkList(DuLinkList L) {
    DuLNode *cur = L->rLink;
    while (cur != NULL) {
        printf("%d(%d) ", cur->data, cur->freq);
        cur = cur->rLink;
    }
    printf("\n");
}

int main() {
    int list[] = {1, 2, 2, 3, 3, 3, 4, 5, 5, 6, 7};

    DuLinkList L = (DuLinkList) malloc(sizeof(DuLNode));
    L->lLink = NULL;
    L->rLink = NULL;
    for (const auto &item: list){
        DuLNode *node = (DuLNode *) malloc(sizeof(DuLNode));
        node->data = item;
        node->freq = 0;
        node->lLink = NULL;
        node->rLink = NULL;
        DuLNode *cur = L;
        while (cur->rLink != NULL) {
            cur = cur->rLink;
        }
        cur->rLink = node;
        node->lLink = cur;
    }
    printDuLinkList(L);

    Locate(L,1);
    printDuLinkList(L);

    Locate(L,5);
    printDuLinkList(L);

    Locate(L,5);
    printDuLinkList(L);


    Locate(L,1);
    printDuLinkList(L);

    Locate(L,1);
    printDuLinkList(L);


}