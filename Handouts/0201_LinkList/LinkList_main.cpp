//
// Created by maicaoboy on 2023/10/29.
//

#include "LinkList.cpp"
#include "stdlib.h"
#include "stdio.h"

int main() {
    int array[] = {1,2,3,4,5,6,7,8,9};
    int randomArray[] = {3,8,1,56,1,4,8,34,1};
    int increaseArray[] = {1,1,5,7,7,8,8,9,10};
    int increaseArrayBig[] = {2,3,4,7,7,9,12,19,100};
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

    create_HeadInsert(L, array, length);
    printLinkList(L);
    free(L);


    /**
     *  测试例题2
     */

    printf("\n*************** 测试2 *********************\n");
    create_TailInsert(L, array, length);
    printLinkList(L);
    freeLinkList(L);


    /**
     *  测试例题3-1
     */

    printf("\n*************** 测试3-1 *********************\n");
    create_TailInsert(L, randomArray, length);
    int max = MaxOne(L->next);
    printf("最大的是: %d\n", max);
    freeLinkList(L);



    /**
     *  测试例题3-2
     */

    printf("\n*************** 测试3-2 *********************\n");
    create_TailInsert(L, array, length);
    int count = countLinkList(L->next);
    printf("链表个数是: %d\n", count);
    freeLinkList(L);

    /**
     *  测试例题3-3
     */

    printf("\n*************** 测试3-3 *********************\n");
    create_TailInsert(L, randomArray, length);
    count = countLinkList(L->next);
    double average = averageLinkList(L->next, count);
    printf("链表平均值: %lf\n", average);
    freeLinkList(L);


    /**
     *  测试例题4
     */

    printf("\n*************** 测试4 *********************\n");
    create_TailInsert(L, array, length);
    printf("链表:");
    printLinkList(L);

    int e;
    ith = 5;
    accessIth(L, ith, e);

    printf("%d 个节点为: %d", ith, e);
    printf("\n");

    freeLinkList(L);



    /**
     *  测试例题5
     */

    printf("\n*************** 测试5 *********************\n");
    create_TailInsert(L, array, length);
    printf("插入前链表:");
    printLinkList(L);
    printf("\n");

    insertBeforeIth(L, 5, 100);

    printf("插入后链表:");
    printLinkList(L);
    printf("\n");

    freeLinkList(L);



    /**
     *  测试例题6
     */

    printf("\n*************** 测试6 *********************\n");
    create_TailInsert(L, array, length);
    printf("查找前链表:");
    printLinkList(L);
    printf("\n");

    ith = 3;

    searchLastMth(L->next, ith, node);

    printf("查找到倒数 %d 个节点数据为: %d", ith, node->data);

    freeLinkList(L);



    /**
     *  测试例题7
     */

    printf("\n*************** 测试7 *********************\n");
    create_TailInsert(L1, array, length);
    printf("删除前链表L1:");
    printLinkList(L1);
    printf("\n");

    create_TailInsert(L2, randomArray, length);
    printf("插入前链表L2:");
    printLinkList(L2);
    printf("\n");

    ith = 3;
    len = 2;

    deleteAndMerge(L1->next, L2->next, ith, len);

    printf("删除后链表L1:");
    printLinkList(L1);
    printf("\n");

    printf("插入后链表L2:");
    printLinkList(L2);
    printf("\n");

    freeLinkList(L1);
    freeLinkList(L2);


    /**
     * 测试例题9
     */
    printf("\n*************** 测试9 *********************\n");
    create_TailInsert(L, increaseArray, length);
    printf("删除前链表L:");
    printLinkList(L);
    printf("\n");

    removeRepeat(L);

    printf("删除后链表L:");
    printLinkList(L);
    printf("\n");

    freeLinkList(L);



    /**
     * 测试例题10
     */
    printf("\n*************** 测试10 *********************\n");
    create_TailInsert(L, increaseArray, length);
    printf("链表L:");
    printLinkList(L);
    printf("\n");


    int x = 8;
    int cnt = 0;
    cnt = countLessThanX(L, x);

    printf("比%d小的数有%d个:", x, cnt);

    freeLinkList(L);



    /**
     * 测试例题11
     */
    printf("\n*************** 测试11 *********************\n");
    create_TailInsert(L1, increaseArray, length);
    printf("删除前链表La:");
    printLinkList(L1);
    printf("\n");

    create_TailInsert(L2, increaseArrayBig, length);
    printf("删除前链表Lb:");
    printLinkList(L2);
    printf("\n");

    removeRepeatInBoth(L1, L2);

    printf("删除后链表La:");
    printLinkList(L1);
    printf("\n");

    freeLinkList(L1);
    freeLinkList(L2);

}








































