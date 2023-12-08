//
// Created by maicaoboy on 2023/12/6.
//
#include "stdio.h"
#include "stdlib.h"


/**
* 给定一个单链表存储的互异整数数列，编写算法，求出所有的递增和递减序列的数目
 * 例如数列7,2,6,9,8,3,5,2,1，可分为(,2) (2,6,9) (9,8,3) (3,5) (5,2,1)共5个数列子数列，结果为5。
 */

/**
 * 算法思想:以递增序列为例,使用pre和cur指针分别指向前后相邻节点遍历链表,每次比较pre指针是否小于cur指针
 * 如果pre指针的值小于cur指针的值,则cnt计数加一,每次遇到pre指针大于等于cur的值时,若cnt>0则说明出现一个递增序列,此时再将cnt置为0,继续向后遍历
 * 递减序列原理相同
 */
typedef struct LinkNode {
    int data;
    LinkNode *next;
} LinkNode, *LinkList;


int countArray(LinkList L) {//不带头结点
    if (L == NULL) return 0;
    int count = 0;
    LinkNode *pre = L, *cur = L->next;
    //找递增
    int cnt = 0;
    while (cur != NULL) {
        if (pre->data >= cur->data) {
            if (cnt > 0) {
                count++;
            }
            cnt = 0;
        } else {
            cnt++;
        }
        pre = cur;
        cur = cur->next;
    }
    if (cnt) count++;

     pre = L, cur = L;
     //找递减
     cnt = 0;
     while(cur != NULL) {
         if(pre->data <= cur->data) {
             if(cnt > 0) {
                 count++;
             }
             cnt = 0;
         }else {
             cnt++;
         }
         pre = cur;
         cur = cur->next;
     }
     if(cnt) count++;
    return count;
}

void printLinkList(LinkList L) {
    LinkNode *p = L;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


int main() {
    int array[] = {7, 2, 6, 9, 8, 3, 5, 2, 1};
    LinkList L = (LinkList) malloc(sizeof(LinkNode));
    L->data = array[0];
    L->next = NULL;
    LinkNode *pre = L;
    for (int i = 1; i < 9; ++i) {
        LinkNode *node = (LinkNode *) malloc(sizeof(LinkNode));
        node->data = array[i];
        node->next = NULL;
        pre->next = node;
        pre = node;
    }
    printLinkList(L);
    printf("count: %d\n", countArray(L));
}














































