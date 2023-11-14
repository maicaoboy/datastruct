//
// Created by maicaoboy on 2023/11/14.
//
#include "stdio.h"
#include "stdlib.h"


//链地址法
#define ElemType int
int hashNum = 10;

typedef struct LinkNode {
    ElemType data;
    LinkNode *next;
}LinkNode, *LinkList;

typedef struct HashTable {
    LinkNode **pList;
    int kNum;
    int size;
}HashTable;


void initial_hTable(HashTable &table, int size) {
    table.size = size;
    table.kNum = 0;
    table.pList = (LinkNode**) malloc(sizeof (LinkNode*) * size);
    for(int i = 0; i < size; i++) {
        table.pList[i] = NULL;
    }
}

//例题2: 创建一个存储空间为 N 且使用链地址法解决冲突的哈希表
HashTable createHashTableLink(int N) {
    HashTable table;
    initial_hTable(table, N);
    return table;
}




/**
 * 例题6:设计算法在链地址法解决冲突的哈希表中插入一个关键字k, 要求:先在哈希表中查找关健字K，
 * 如果关健字k存在于表中，则查找成功,不再执行插入糠作，
 * 如果关健字k不存在于表中，则查找失败，执行插入操作，将K插入表中。
 * @param table
 * @param key
 */
void insertKey(HashTable &table, ElemType key) {
    int index = key % table.size;
    LinkNode *pre = NULL;
    LinkNode *cur = table.pList[index];

    LinkNode *node = (LinkNode*) malloc(sizeof(LinkNode));
    node->data = key;
    node->next = NULL;

    while(cur != NULL && cur->data != key) {
        pre = cur;
        cur = cur->next;
    }
    if(pre == NULL && cur == NULL) {
        table.pList[index] = node;
        table.kNum++;
    }else if(cur == NULL){
        node->next = cur;
        pre->next = node;
        table.kNum++;
    }else {
        free(node);
    }
};



/**
 * 例题7:设计算法在链地址法解决冲突的哈希表中删除关键字 k。
 * 要求:先在哈希表中查找关键字 k ,如果关键字 k 存在于表中，则查找成功，执行删除操作;
 * 如果关键字k不存在于表中，则查找失败，不执行删除操作。
 * @param table
 * @param key
 */
void deleteKey(HashTable &table, ElemType key) {
    int index = key % table.size;
    LinkNode *pre = NULL;
    LinkNode *cur = table.pList[index];

    while(cur != NULL) {
        if(cur->data == key) {
            LinkNode *node = NULL;
            if(cur == table.pList[index]) {
                node = cur;
                table.pList[index] = cur->next;
            }else {
                node = cur;
                pre->next = cur->next;
            }
            table.kNum--;
            free(node);
            break;
        }
        pre = cur;
        cur = cur->next;
    }
}

void visit(LinkNode *node) {
    printf("%d ", node->data);
}

void traverseLinkHashTable(HashTable table) {
    printf("遍历链地址哈希表,size: %d, keyNum: %d\n", table.size, table.kNum);
    for(int i = 0; i < table.size; i++) {
        LinkNode *pre = NULL;
        LinkNode *cur = table.pList[i];
        while(cur != NULL) {
            visit(cur);
            cur = cur->next;
        }
        printf("\n");
    }
}
































