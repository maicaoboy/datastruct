//
// Created by maicaoboy on 2023/11/27.
//
#include "stdio.h"
#include "stdlib.h"

#define KeyType int
#define TableSize 7
#define PRIME 7               //定义哈希函数Hash(key) = key % 7

typedef struct LinkNode {   //处理冲突的结构体
    KeyType key;
    LinkNode *next;
}LinkNode, *LinkList;


struct HashTable {          //散列表
    LinkList *list;
    int length;
};

int hash(KeyType key) {
    return key % PRIME;
}

//初始化哈希表List数组为空,并初始化长度为0
void createHashTable(HashTable &table, int size) {
    table.length = size;
    table.list = (LinkList*) malloc(sizeof (LinkList) * size);
    for (int i = 0; i < TableSize; ++i) {
        table.list[i] = NULL;
    }
}



//插入关键字:首先使用hash(key)函数查找插入位置,使用尾插法在查找到的位置插入key,使用尾插法可以在插入时确认key是否重复插入
void insertKey(HashTable &table, KeyType key) {
    int index = hash(key);
    if(table.list[index] == NULL) {
        LinkNode *node = (LinkNode*) malloc(sizeof (LinkNode));
        node->key = key;
        node->next = NULL;
        table.list[index] = node;
        table.length++;
    }else {
        LinkNode *pre = table.list[index];
        LinkNode *cur = table.list[index];
        while(cur != NULL) {
            if(cur->key == key) {
                return;
            }else {
                pre = cur;
                cur = cur->next;
            }
        }
        LinkNode *node = (LinkNode*) malloc(sizeof (LinkNode));
        node->key = key;
        node->next = NULL;
        pre->next = node;
        table.length++;
    }
}



//删除关键字:首先使用哈希函数hash(key)查找插入位置,并在查找到的位置查找key并删除
void deleteKey(HashTable &table, KeyType key) {
    int index = hash(key);
    LinkNode *pre = table.list[index];
    LinkNode *cur = table.list[index];
    while(cur != NULL) {
        if(cur->key == key) {
            LinkNode *node = cur;
            if(pre == cur) {
                table.list[index] = table.list[index]->next;
            }else {
                pre->next = cur->next;
            }
            free(node);
            return;
        }
        pre = cur;
        cur = cur->next;
    }
}

//printHashTable
void printHashTable(HashTable table) {
    printf("-------------------begin-------------------\n");
    for (int i = 0; i < TableSize; ++i) {
        printf("%d: ", i);
        LinkNode *cur = table.list[i];
        while(cur != NULL) {
            printf("%d ", cur->key);
            cur = cur->next;
        }
        printf("\n");
    }
    printf("--------------------end--------------------\n");
}

int main() {
    //测试哈希表
    HashTable table;
    createHashTable(table);
    insertKey(table, 5);
    insertKey(table, 121);
    insertKey(table, 192);
    insertKey(table, 263);
    insertKey(table, 335);
    insertKey(table, 406);
    insertKey(table, 478);
    insertKey(table, 548);
    insertKey(table, 613);
    insertKey(table, 687);
    insertKey(table, 752);
    insertKey(table, 826);
    insertKey(table, 898);
    insertKey(table, 96);
    insertKey(table, 103);
    insertKey(table, 110);
    insertKey(table, 117);
    insertKey(table, 124);

    printHashTable(table);

    deleteKey(table, 898);
    deleteKey(table, 261);
    deleteKey(table, 544);
    deleteKey(table, 681);
    deleteKey(table, 96);
    deleteKey(table, 687);

    printHashTable(table);

}

