//
// Created by maicaoboy on 2023/10/29.
//
#include "stdlib.h"
#include "stdio.h"

typedef struct LinkNode {
    int data;
    LinkNode * next;
} LinkNode, *LinkList;



//使用头插法构建带头节点的的单链表
/**
 * 获取一个LinkNode
 * @param data 节点数据
 * @return
 */
LinkNode* getLinkNode(int data) {
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
        printf("%d ", ptr->data);
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
        printf("%d ", ptr->data);
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
void create_HeadInsert(LinkList &L, int array[], int length) {
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
void create_TailInsert(LinkList &L, int array[], int length) {
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
 * 已知L为带头节点的单链表,,请按照递归的思想完成下列运算:
 * (1) 求链表中的最大整数
 * @param L     待求链表
 * @return      最大值
 */
int MaxOne(LinkNode* L) {
    if(L->next == NULL) {
        return L->data;
    }else {
        int max = MaxOne(L->next);
        return L->data >= max ? L->data : max;
    }
}



/**
 * 已知L为带头节点的单链表,,请按照递归的思想完成下列运算:
 * (2) 求链表中的最大整数
 * @param L     待求链表
 * @return      链表个数
 */
int countLinkList(LinkNode *L) {
    if(L == NULL) {
        return 0;
    }else {
        return 1 + countLinkList(L->next);
    }
}


/**
 * 已知L为带头节点的单链表,,请按照递归的思想完成下列运算:
 * (3) 求链表的平均值
 * @param L     待求链表
 * @param n     链表总个数
 * @return      链表平均值
 */
double averageLinkList(LinkNode *L, int n) {
    if(L == NULL) {
        return (double)0;
    }else {
        return (double)L->data / n + averageLinkList(L->next, n);
    }
}


/**
 * 单链表访问第 ith 个数据节点
 * @param L         待访问链表
 * @param ith       第 ith 个节点
 * @param e         存储访问节点
 */
void accessIth(LinkList L, int ith, int &e) {
    int i = 0;
    LinkNode *ptr = L;

    while(i < ith && ptr != NULL) {
        ptr = ptr->next;
        i++;
    }

    e = ptr->data;
}


/**
 * 例题5: 在第 ith 个数据节点前插入元素 e
 * @param L         待插入链表
 * @param ith       待插入位置
 * @param e         待插入元素
 */
void insertBeforeIth(LinkList L, int ith, int e) {
    if(ith < 1) {
        return;
    }

    LinkNode *ptr = L;
    int i = 0;

    while(i < ith - 1 && ptr != NULL) {
        ptr = ptr->next;
        i++;
    }

    LinkNode *node = getLinkNode(e);
    node->next = ptr->next;
    ptr->next = node;
}


/**
 * 例题6
 * 设计高效算法查找带头节点单链表导数第 m 个位置的节点并输出该结点值
 * @param L         待查找链表
 * @param m         倒数第 m 个
 * @param node      保存查找到的结点
 */
void searchLastMth(LinkList L, int m, LinkNode *&node) {
    LinkNode *fast = L->next;
    LinkNode *slow = L->next;
    int i = 0;

    while(fast != NULL && i < m) {
        fast = fast->next;
        i++;
    }

    while(fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    node = slow;
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
 *例题7
 * 已知指针La Lb分别指向两个无头结点的单链表,编写函数完成从La中删除第j个结点开始的len个结点,并将这些节点插入到L2的第j个元素前
 * !!!当j为1时需要对头节点进行特殊操作,所以操作前先加空头结点
 * @param L1    链表
 * @param L2    链表
 * @param j     删除起始位置
 * @param len   删除长度
 */
void deleteAndMerge(LinkList &L1, LinkList &L2, int j, int len){
    LinkNode *head1 = (LinkNode*) malloc(sizeof(LinkNode));
    LinkNode *head2 = (LinkNode*) malloc(sizeof(LinkNode));
    head1->next = L1;
    head2->next = L2;

    LinkNode *nodeL1 = preOfIth(head1, j);
    LinkNode *nodeL1Len = preOfIth(head1, j + len);
    LinkNode *nodeL2 = preOfIth(head2, j);

    LinkNode *cutDown =  nodeL1->next;
    nodeL1->next = nodeL1Len->next;
    nodeL1Len->next = nodeL2->next;
    nodeL2->next = cutDown;

    L1 = head1->next;
    L2 = head2->next;
}


































































