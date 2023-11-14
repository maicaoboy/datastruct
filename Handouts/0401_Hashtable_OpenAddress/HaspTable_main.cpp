//
// Created by maicaoboy on 2023/11/14.
//
#include "HashTable.cpp"

int main() {
    ElemType array[] = {2,7,13,9,34,76,23,34,98,12,87,39,99};
    int size = 13;
    int length = 20;
    HashTable table;

    initialDi_linger(length);

    table = createHashTable_Open(20);
    for(int i = 0; i < size; i++) {
        insertKey(table, array[i]);
    }
    printf("哈希表结构:");
    for(int i = 0; i < length; i++) {
        printf("%d ", table.pList[i]);
    }
    printf("\n");

    deleteKey(table, 88);
    printf("删除88后哈希表结构:");
    for(int i = 0; i < length; i++) {
        printf("%d ", table.pList[i]);
    }
    printf("\n");

    deleteKey(table, 99);
    printf("删除99后哈希表结构:");
    for(int i = 0; i < length; i++) {
        printf("%d ", table.pList[i]);
    }
    printf("\n");

    deleteKey(table, 76);
    printf("删除76后哈希表结构:");
    for(int i = 0; i < length; i++) {
        printf("%d ", table.pList[i]);
    }
    printf("\n");

    destroy(table);

}