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
    while(ptr) {
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
    while(ptr) {
        printf("%c ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeLinkList(LinkList &L) {
    LinkNode *ptr = L;
    while(ptr) {
        free(ptr);
        ptr = ptr->next;
    }
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
    L->next = NULL;
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
    L->next = NULL;
    L->data = -1;

    LinkNode *pTail = L;

    for(int i = 0; i < length; i++) {
        LinkNode *node = (LinkNode*)malloc(sizeof(LinkNode));
        node->data = array[i];
        node->next = NULL;
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

    for(int i = 0; i < ith - 1 && ptr != NULL ; i++) {
        ptr = ptr->next;
    }

    return ptr;
}


/**
 * 例题8
 * 设单链表表头指针为L,节点数据域为字符.设计时间复杂度最低的算法判断前 n/2 个字符是否与后 n/2 个字符依次相同.
 * @param L     假设L为带头结点的单链表
 * @param n     链表共有n个数据结点
 * @return
 */
int isSame(LinkList L, int n) {
    int i = 0;
    LinkNode *slow = L->next;
    LinkNode *fast = L->next;

    while(i < n / 2 && fast != NULL) {
        i++;
        fast = fast->next;
    }

    if(n % 2 && fast != NULL) {
        fast = fast->next;
    }

    while(fast != NULL) {
        if(slow->data != fast->data) {
            return 0;
        }
        slow = slow->next;
        fast = fast->next;
    }

    return 1;
}

































































