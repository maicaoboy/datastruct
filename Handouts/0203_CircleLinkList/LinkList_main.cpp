//
// Created by maicaoboy on 2023/10/29.
//

#include "LinkList.cpp"
#include "stdlib.h"
#include "stdio.h"

int main() {
    int array[] = {1,2,3,4,5,6,7,8,9};
    int randomArray[] = {3,8,1,56,1,4,8,34,1};
    int increaseArray[] = {1,2,5,7,7,8,8,9,10};
    int increaseArrayBig[] = {2,3,4,7,7,9,12,19,100};
    int array1[] = {2,3,5,7,9,10,13,14,15};
    int array2[] = {1,2,3,4,5,7,12,13,118};
    int length = 9;
    int len;
    int ith = 0;
    int min = 0;
    int max = 0;
    LinkNode *node = NULL;
    LinkList L;
    LinkList L1;
    LinkList L2;


    /**
     * 测试例题21
     */
    printf("\n*************** 测试21 *********************\n");
    createCircleList_headInsert(L, increaseArray, length);
    printf("头插法链表L:");
    printLinkList(L);
    printf("\n");
    freeLinkList(L);

    createCircleList_tailInsert(L, increaseArray, length);
    printf("尾插法链表L:");
    printLinkList(L);
    printf("\n");
    freeLinkList(L);


    /**
     * 测试例题22
     */

    printf("\n*************** 测试22 *********************\n");
    createCircleList_tailInsert(L, increaseArray, length);
    printf("循环链表L:");
    printLinkList(L);
    printf("\n");

    reverse(L);

    printf("逆置后的循环链表L:");
    printLinkList(L);
    printf("\n");

    freeLinkList(L);



    /**
     * 测试例题23
     */

    printf("\n*************** 测试23 *********************\n");
    createCircleList_tailInsert(L, increaseArray, length);
    printf("循环链表L:");
    printLinkList(L);
    printf("\n");

    len = 3;
    leftMoveKStep(L, len);

    printf("逆置后的循环链表L:");
    printLinkList(L);
    printf("\n");

    freeLinkList(L);

    /**
     * 测试例题24
     */

    printf("\n*************** 测试24 *********************\n");
    createCircleList_tailInsert(L, increaseArray, length);
    printf("循环链表L:");
    printLinkList(L);
    printf("\n");

    node = L->next->next;
    int data = node->data;
    removeBefore(node);


    printf("删除:%d后的L:", data);
    printLinkList(L);
    printf("\n");

    freeLinkList(L);

    printf("\n*************** 测试26 *********************\n");
    createCircleList_tailInsert(L, increaseArray, length);
    printf("循环链表L:");
    printLinkList(L);
    printf("\n");

    reverseIthToMth(L, L1, 3, 6);


    printf("L:");
    printLinkList(L);
    printf("\n");

    printf("L1:");
    printLinkList(L1);
    printf("\n");

    freeLinkList(L);


    printf("\n*************** 测试27 *********************\n");
    createCircleList_tailInsert(L1, increaseArray, length);
    printf("循环链表La:");
    printLinkList(L1);
    printf("\n");

    createCircleList_tailInsert(L2, randomArray, length);
    printf("循环链表La:");
    printLinkList(L2);
    printf("\n");

    merge_better(L1, L2, 9, 9);


    printf("合并后链表:");
    printLinkList(L1);
    printf("\n");


    freeLinkList(L1);



    printf("\n*************** 测试28 *********************\n");

    createCircleList_tailInsert_ToTail(L, array, length);


    printf("L:");
    printLinkList(L->next);
    printf("\n");


    freeLinkList(L);


    printf("\n*************** 测试29 *********************\n");
    createCircleList_tailInsert_ToTail(L1, increaseArray, length);
    printf("循环链表La:");
    printLinkList(L1->next);
    printf("\n");

    createCircleList_tailInsert_ToTail(L2, randomArray, length);
    printf("循环链表La:");
    printLinkList(L2->next);
    printf("\n");

    combineCircleLinkList(L1, L2);


    printf("合并后链表:");
    printLinkList(L1->next);
    printf("\n");


    freeLinkList(L1);














}











































