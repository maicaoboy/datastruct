//
// Created by maicaoboy on 2023/12/8.
//
#include "stdio.h"
#include "stdlib.h"

#define ELemType int

typedef struct LinkNode{
    ELemType data;
    LinkNode *next;
}LinkNode, *LinkList;


/**
 * Q1:有序单链表LA、LB 的结点值为整数，LA 为非递增有序表，LB 为递增有序表。
 * 构造一个递增有序循环链表 LC，其结点值同时出现在 LA、LB 两个单链表中，且 LC 中的结点值不重复。
*/
/**
 * 算法思想:将LB逆序为非递减有序表,之后使用最小值法遍历两个链表找出相同节点插入LC中
 */

void reverse(LinkList L) {
    LinkNode *cur = L->next;
    L->next = NULL;

    //使用头插法反转链表
    while(cur!= NULL) {
        cur = L->next;
        L->next = cur;
        cur = cur->next;
    }
}

void theSame(LinkList La, LinkList Lb, LinkList &Lc) {      //La,Lb,Lc均为带头结点单链表
    Lc = (LinkNode*) malloc(sizeof (LinkNode));
    Lc->next = Lc;
    Lc->data = -999;

    reverse(Lb);

    La = La->next;
    Lb = Lb->next;

    while(La != NULL && Lb != NULL) {
        if(La->data == Lb->data) {
            LinkNode *node = La;
            La = La->next;
            Lb = Lb->next;
            if(Lc->next == Lc || node->data != Lc->next->data) {        //如果Lc为空或者当前相等的节点在Lc不存在,则进行插入操作
                node->next = Lc->next;
                Lc->next = node;
            }
        }
    }
    while(La != NULL) {
        LinkNode *node = La;
        La = La->next;
        if(Lc->next == Lc || node->data != Lc->next->data) {        //如果Lc为空或者当前相等的节点在Lc不存在,则进行插入操作
            node->next = Lc->next;
            Lc->next = node;
        }
    }

    while(Lb != NULL) {
        LinkNode *node = Lb;
        Lb = Lb->next;
        if(Lc->next == Lc || node->data != Lc->next->data) {        //如果Lc为空或者当前相等的节点在Lc不存在,则进行插入操作
            node->next = Lc->next;
            Lc->next = node;
        }
    }
}













