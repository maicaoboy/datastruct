//
// Created by lhb on 2023/10/30.
//
#include "LinkList_char.cpp"

int main() {
    char array[] = {'a','b','c','d','e','f','g','h','i'};
    char randomArray[] = {'1','a','c','.','0','1','a','c','.'};
    int length = 9;
    int len;
    int ith = 0;
    LinkNode *node = NULL;
    LinkList L;
    LinkList L1;
    LinkList L2;


    /**
     * 测试例题1
     */

    printf("*************** 测试1 *********************\n");
    create_TailInsert(L, randomArray, length);
    printLinkList(L);
    int result = isSame(L, length);
    if(result) {
        printf("一样\n");
    }else {
        printf("不一样");
    }




















}