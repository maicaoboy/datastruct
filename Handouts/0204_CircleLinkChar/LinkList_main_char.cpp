//
// Created by lhb on 2023/10/30.
//
#include "LinkList_char.cpp"

int main() {
    char array[] = {'a','b','c','d','e','f','g','h','i'};
    char randomArray[] = {'1','a','c','.','0','1','a','c','!'};
    int length = 9;
    int len;
    int ith = 0;
    LinkNode *node = NULL;
    LinkList L;
    LinkList L1;
    LinkList L2;
    LinkList L3;


    /**
     * 测试例题1
     */

    printf("*************** 测试5 *********************\n");
    create_TailInsert(L, randomArray, length);
    printf("原链表L:");
    printLinkList(L);
    printf("\n");

    splitLinkList(L, L1, L2, L3);

    printf("字母链表L1:");
    printLinkList(L1);
    printf("\n");

    printf("数字链表L2:");
    printLinkList(L2);
    printf("\n");

    printf("其他字符链表L3:");
    printLinkList(L3);
    printf("\n");

    freeLinkList(L1);
    freeLinkList(L2);
    freeLinkList(L3);






















}