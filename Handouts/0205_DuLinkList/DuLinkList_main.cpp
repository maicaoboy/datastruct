//
// Created by xiang on 2023/11/2.
//
#include "DuLinkList.cpp"


int main() {
    int array[] = {1,2,3,4,5,6,7,8,9};
    int randomArray[] = {3,8,1,56,1,4,8,34,1};
    int increaseArray[] = {1,1,5,7,7,8,8,9,10};
    int increaseArrayBig[] = {2,3,4,7,7,9,12,19,100};
    int array1[] = {2,3,5,7,9,10,13,14,15};
    int array2[] = {1,2,3,4,5,7,12,13,118};
    int length = 9;
    int len;
    int ith = 0;
    int min = 0;
    int max = 0;
    DuLinkNode *node = NULL;
    DuLinkList L;
    DuLinkList L1;
    DuLinkList L2;


    /**
     * 测试基本方法
     */
    create_tailInsert(L, array, length);
    printf("链表L:");
    printList(L);
    printf("\n");
    freeLinkList(L);


    /**
     * 测试30
     */

    printf("\n*************** 测试30 *********************\n");
    create_tailInsert(L, randomArray, length);
    sortDuLinkList(L);
    printf("链表L:");
    printList(L);
    printf("\n");

    printf("逆序打印链表L:");
    printList_prior(L);
    printf("\n");

    freeLinkList(L);






}