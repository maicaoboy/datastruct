//
// Created by maicaoboy on 2023/11/14.
//
#include "HashTable.cpp"

int main() {
    ElemType array[] = {2,7,13,9,34,76,23,34,98,12,87,39,99};
    int size = 13;
    HashTable table;

    table = createHashTableLink(10);
    for(int i = 0; i < size; i++) {
        insertKey(table, array[i]);
    }
    printf("原始哈希表:\n");
    deleteKey(table, 3);
    traverseLinkHashTable(table);

    printf("删除3后:\n");
    deleteKey(table, 3);
    traverseLinkHashTable(table);

    printf("删除2后:\n");
    deleteKey(table, 2);
    traverseLinkHashTable(table);

    printf("删除23后:\n");
    deleteKey(table, 23);
    traverseLinkHashTable(table);

    printf("删除34后:\n");
    deleteKey(table, 34);
    traverseLinkHashTable(table);


}