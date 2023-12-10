//
// Created by maicaoboy on 2023/12/9.
//
#include "stdio.h"
#include "stdlib.h"
/**
 *  设计一个实现下述要求的 locate 运算的函数，设有一个带表头结点的双向链表L，
 * 每个结点有4个数据成员:指向前驱节点的指针 prior，指向后继节点的指针 next，
 * 存放数据的成员 data 和访问频度 freq，所有结点的 freq 初始值都为 0。
 * 每当在链表上进行一次 locate(DuL,x )操作时，令元素值为x 的结点访问频度 freq 加 1，
 * 同时调整链表中结点间的顺序。使链表中所有结点按访问频度递减的顺序排列。注意:该双链表中无数据域重复的结点。
*/

/**
 * 算法思想:首先顺序查找值为x的节点,在查找到x节点后将其freq+1;之后若其前驱节点的freq小于于当前节点,则不断将node向表头移动一位
 */

#define ElemType int

typedef struct DuLinkNode {
    ElemType data;
    int freq;
    DuLinkNode *prior, *next;
}DuLinkNode, *DuLinkList;

void swap(DuLinkList DuL, DuLinkNode *node) {
    DuLinkNode *pre = node->prior;
    DuLinkNode *ppre = node->prior->prior;
    pre->next = node->next;
    node->next->prior = pre;
    node->next = pre;
    node->prior = ppre;
    pre->prior = node;
    ppre->next = node;
}


DuLinkNode* locate(DuLinkList DuL, ElemType x) {
    DuLinkNode *node = DuL->next;
    while(node != NULL) {
        if(node->data == x) {
            node->freq++;
            while(node->freq > node->prior->freq && node->prior != DuL) {
                swap(DuL, node);
//                node = node->prior;
            }
            return node;
        }
    }
    return NULL;
}

void moveTo(DuLinkNode *pre, DuLinkNode *node) {
    node->prior->next = node->next;
    if(node->next != NULL) node->next->prior = node->prior;
    node->next = pre->next;
    node->prior = pre;
    pre->next = node;
    node->next->prior = node;
}


DuLinkNode* locate_better(DuLinkList DuL, ElemType x) {
    DuLinkNode *node = DuL->next;
    while(node != NULL) {
        if(node->data == x) {
            node->freq++;
            DuLinkNode *pre = node->prior;
            while(node->freq > pre->freq && pre != DuL) {
                pre = pre->prior;
            }
            if(pre->next != node) moveTo(pre, node);      //将node转移到pre后
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void printDUL(DuLinkList DuL) {
    DuLinkNode *node = DuL->next;
    while(node != NULL) {
        printf("%d(%d) ", node->data, node->freq);
        node = node->next;
    }
    printf("\n");
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6,7};
    DuLinkList DuL = (DuLinkList)malloc(sizeof(DuLinkNode));
    DuL->next = NULL;
    DuL->prior = NULL;
    DuLinkNode *pre = DuL;
    for (int i = 0; i < 7; ++i) {
        DuLinkNode *node = (DuLinkNode*)malloc(sizeof(DuLinkNode));
        node->data = array[i];
        node->freq = 0;
        node->prior = pre;
        node->next = NULL;
        pre->next = node;
        pre = node;
    }
    printDUL(DuL);
    locate_better(DuL, 3);
    locate_better(DuL, 7);
    locate_better(DuL, 7);
    locate_better(DuL, 8);
    locate_better(DuL, 8);
    locate_better(DuL, 8);
    printDUL(DuL);
}