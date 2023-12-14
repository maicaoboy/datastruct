//
// Created by maicaoboy on 2023/12/10.
//
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
}LinkNode, *LinkList;

/**
 * 设计一个算法,判断一个单链表的各个节点值是否有序
 * 算法思想:首先找出第一对不相等的值,以此判断链表为升序or降序,之后遍历剩余节点,其余节点必须满足升序or降序or相等
 * @param L
 * @return
 */


int isOrder(LinkList L) {
    LinkNode *pre = L->next;
    if(pre == NULL) return 1;       //仅有一个点的序列,有序
    LinkNode *cur = pre->next;
    while(cur != NULL) {
        if(pre->data != cur->data) {
            break;
        }
        cur = cur->next;
    }
    if(cur == NULL) return 1;       //这是一个常数序列,有序
    int status  = cur->data - pre->data;    //大于0为升序,小于0为降序
    int flag = 1;                   //标记为有序
    pre = cur;
    cur = cur->next;
    while(cur != NULL) {            //判断剩余节点是否有序
        if(status > 0 && (cur->data - pre->data) < 0) {         //升序序列但当前节点小于前驱节点
            flag = 0;
            break;
        }else if(status < 0 && (cur->data - pre->data) > 0) {   //同上
            flag = 0;
            break;
        }
        pre = cur;
        cur = cur->next;
    }
    return flag;
}



int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};    //升序序列
    int array2[] = {8, 7, 6, 5, 5, 3, 2, 2};   //降序序列
    int array3[] = {1, 1, 1, 1, 1, 1, 1, 1};   //常数序列
    int array4[] = {1, 3, 4, 5, 6, 7, 8, 7};    //非有序序列
    LinkList L = (LinkList)malloc(sizeof(LinkNode));
    LinkNode *ptr = L;
    for(int i = 0; i < 8; i++) {
        LinkNode *node = (LinkNode*)malloc(sizeof(LinkNode));
        node->data = array2[i];
        node->next = NULL;
        ptr->next = node;
        ptr = node;
    }
    printf("%d\n", isOrder(L));
}

