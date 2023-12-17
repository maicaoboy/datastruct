//
// Created by maicaoboy on 2023/12/17.
//
#include "stdio.h"
#include "stdlib.h"

typedef struct Book {
    char name[20];
    int number;
    struct {
        int year;
        int month;
        int day;
    } date;
    struct Book *next;
} LinkNode, *LinkList;


int compareDate(LinkNode *node1, LinkNode *node2) {
    if(node1->date.year != node2->date.year) {
        return node1->date.year - node2->date.year;
    } else if(node1->date.month != node2->date.month) {
        return node1->date.month - node2->date.month;
    } else if(node1->date.day != node2->date.day){
        return node1->date.day - node2->date.day;
    }
    return 0;
}


void insert(LinkList &L, LinkNode *node) {
    LinkNode *ptr = L->next;
    LinkNode *pre = L;
    while(ptr != NULL) {
        if(compareDate(ptr, node) < 0) {
            break;
        }
        pre = ptr;
        ptr = ptr->next;
    }
    pre->next = node;
    node->next = ptr;
    if(pre != L && compareDate(pre, node) == 0) {
        node->number += pre->number;
    }
}


void getSameDate(LinkList &L) {
    LinkNode *ptr = L->next;
    L->next = NULL;
    while (ptr != NULL) {
        LinkNode *temp = ptr->next;
        insert(L, ptr);
        ptr = temp;
    }
    LinkNode *pre = L->next;
    ptr = L->next;
    while(ptr != NULL) {
        if(compareDate(pre, ptr) != 0) {
            printf("%s %d %d-%d-%d\n", pre->name, pre->number, pre->date.year, pre->date.month, pre->date.day);
        }
        pre = ptr;
        ptr = ptr->next;
    }
    printf("%s %d %d-%d-%d\n", pre->name, pre->number, pre->date.year, pre->date.month, pre->date.day);

}

void print(LinkList L) {
    LinkNode *ptr = L->next;
    while(ptr != NULL) {
        printf("%s %d %d-%d-%d\n", ptr->name, ptr->number, ptr->date.year, ptr->date.month, ptr->date.day);
        ptr = ptr->next;
    }
    printf("\n\n");
}

void destroy(LinkList &L) {
    LinkNode *ptr = L;
    while(ptr != NULL) {
        LinkNode *temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
}



int main() {
    LinkList L = (LinkList)malloc(sizeof(LinkNode));
    L->next = NULL;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        LinkNode *node = (LinkNode*)malloc(sizeof(LinkNode));
        scanf("%s %d %d-%d-%d\n", node->name, &node->number, &node->date.year, &node->date.month, &node->date.day);
        node->next = L->next;
        L->next = node;
    }
    getSameDate(L);
    printf("\n");
//    print(L);
    return 0;
}


/**
9
aaaa 3 2020-10-3
bbbb 3 2020-10-8
cccc 3 2021-9-3
aaaa1 3 2020-10-3
bbbb1 3 2020-10-8
cccc1 3 2021-9-3
aaaa2 3 2020-10-3
bbbb3 3 2020-10-8
cccc2 3 2021-9-3
 */
