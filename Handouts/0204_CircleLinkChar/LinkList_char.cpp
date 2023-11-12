//
// Created by maicaoboy on 2023/10/29.
//
#include "stdlib.h"
#include "stdio.h"
typedef char ELemType;

typedef struct LinkNode {
    ELemType data;
    LinkNode * next;
} LinkNode, *LinkList;



//使用头插法构建带头节点的的单链表
/**
 * 获取一个LinkNode
 * @param data 节点数据
 * @return
 */
LinkNode* getLinkNode(ELemType data) {
    LinkNode *node = (LinkNode*) malloc(sizeof(LinkNode));
    node->data = data;
    node->next = NULL;
    return node;
}

/**
 * 打印带头结点的链表
 * @param L 要打印的链表
 */
void printLinkList(LinkList L) {
    LinkNode *ptr = L->next;
    while(ptr != L) {
        printf("%c ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

/**
 * 打印带头结点的链表
 * @param L 要打印的链表
 */
void printLinkListWithoutHead(LinkList L) {
    LinkNode *ptr = L->next;
    while(ptr != L) {
        printf("%c ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeLinkList(LinkList &L) {
    LinkNode *ptr = L;
    while(ptr != L) {
        LinkNode *node = ptr;
        ptr = ptr->next;
        free(node);

    }
    free(L);
    L = NULL;
}


/**
 * 例题1: 使用头插法构建带头节点的单链表
 * @param L         头节点指针
 * @param array     数据
 * @param length    数据个数
 */
void create_HeadInsert(LinkList &L, ELemType array[], int length) {
    L = (LinkNode*) malloc(sizeof(LinkNode));
    L->next = L;
    L->data = -1;

    for(int i = 0; i < length; i++) {
        LinkNode *node = (LinkNode*) malloc(sizeof(LinkNode));
        node->data = array[i];
        node->next = L->next;
        L->next = node;
    }
}

/**
 * 例题2: 使用尾插法构建带头节点的单链表
 * @param L         头节点指针
 * @param array     数据
 * @param length    数据个数
 */
void create_TailInsert(LinkList &L, ELemType array[], int length) {
    L = (LinkNode*) malloc(sizeof(LinkNode));
    L->next = L;
    L->data = -1;

    LinkNode *pTail = L;

    for(int i = 0; i < length; i++) {
        LinkNode *node = (LinkNode*)malloc(sizeof(LinkNode));
        node->data = array[i];
        node->next = pTail->next;
        pTail->next = node;
        pTail = node;
    }
}


/**
 * 查找 ith 个结点的前驱节点(辅助函数)
 * @param node      带头节点的单链表
 * @param ith       ith
 * @return          返回查找到的结点
 */
LinkNode *preOfIth(LinkList L, int ith) {
    LinkNode *ptr = L;

    for(int i = 0; i < ith - 1; i++) {
        ptr = ptr->next;
    }

    return ptr;
}



void tailInsert(LinkNode *&tail, LinkNode *node) {
    node->next = tail->next;
    tail->next = node;
    tail = node;
}


//设计算法将一个含有数字, 字母, 和其他字符组成的循环链表拆分成三个循环链表
//媒体哦啊链表只包含一种字符
void splitLinkList(LinkList &L, LinkList &alphabetLink, LinkList &numberLink, LinkList &otherLink) {
    LinkNode *ptr = L->next;

    alphabetLink = (LinkNode*) malloc(sizeof (LinkNode));
    numberLink = (LinkNode*) malloc(sizeof (LinkNode));
    otherLink = (LinkNode*) malloc(sizeof (LinkNode));

    alphabetLink->next = alphabetLink;
    numberLink->next = numberLink;
    otherLink->next = otherLink;

    LinkNode *alphabetTail = alphabetLink;
    LinkNode  *numberTail = numberLink;
    LinkNode *otherTail = otherLink;

    while(ptr != L) {
        LinkNode *node = ptr;
        ptr = ptr->next;
        if(node->data >= 'a' && node->data <= 'z' || node->data >= 'A' && node->data <= 'Z') {
            tailInsert(alphabetTail, node);
        }else if(node->data >= '0' || node->data <= 9) {
            tailInsert(numberTail, node);
        }else {
            tailInsert(otherTail, node);
        };
    }
    free(L);
}

































































