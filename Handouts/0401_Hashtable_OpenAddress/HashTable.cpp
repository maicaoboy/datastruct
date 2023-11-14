//
// Created by maicaoboy on 2023/11/14.
//
#include "stdio.h"
#include "stdlib.h"

//开放地址法

#define ElemType int
#define DiSize 100
int Di[DiSize] = {0};
int hashNum = 19;

typedef struct HashTable {
    ElemType *pList;
    int kNum;
    int tLength;
}HashTable;

#define INF 99999999


void initial_hTable(HashTable &table, int tLength) {
    table.kNum = 0;
    table.tLength = tLength;
    table.pList = (ElemType*)malloc(sizeof(ElemType) * table.tLength);
    for(int i = 0; i < table.tLength; i++) {
        table.pList[i] = INF;
    }
}


/**
 * 例题1: 创建一个存储空间为 N 且使用开放地址法解决冲突的哈希表
 * @param N
 * @return
 */
HashTable createHashTable_Open(int N) {
    HashTable table;
    initial_hTable(table, N);
    return table;
}


void initialDi_linger(int tLength) {
    for(int i = 0; i < DiSize; i++) {
        Di[i] = i;
    }
}

void initialDi_Square(int tLength) {
    Di[0] = 0;
    for(int i = 1; i < DiSize / 2; i++) {
        Di[2 * i - 1] = i * i;
        Di[2 * i] = - i * i;
    }
}

int Hash(ElemType key) {
    return key % hashNum;
}


/**
 * 例题3: 设计算法在开放地址法解决冲突的哈希表中查找关键字的位置.
 * @param table
 * @param key
 * @param pos
 * @return
 */
int findKeyIndex(HashTable table, ElemType key, int &pos) {
    int Hi = Hash(key);
    for(int i = 0; i < table.tLength; i++) {
        int index = (Hi + Di[i]) % table.tLength;
        pos = index;
        if(table.pList[index] == INF) {
            return 0;
        }else if(table.pList[index] == key) {
            return 1;
        }
    }
    return 0;
}

/**
 * 课程版本
 * 例题3: 设计算法在开放地址法解决冲突的哈希表中查找关键字的位置.
 * @param table
 * @param key
 * @param pos
 * @return
 */
int findKeyIndex_handout(HashTable table, ElemType key, int &pos) {
    int Hi = Hash(key);
    int i = 0;
    while(table.pList[Hi] != INF && table.pList[Hi] != key && i < table.tLength) {
        i++;
        Hi = (Hi + Di[i]) % table.tLength;
    }
    pos = Hi;
    if(table.pList[pos] == key) {
        return 1;
    }else {
        return 0;
    }
}


/**
 * 例题 4:设计算法在开放地址法解决冲突的哈希表中插入一个关键字 k.要求:先在哈希表中查找关键字 k,
 * 如果关健字 k 已存在则将 k 已存在于表中, 则查找成功, 不再执行插入操作;
 * 如果关键字k不存在于表中, 则查找失败, 执行插入操作, 哈希表中。
 * @param table
 * @param key
 */
void insertKey(HashTable &table, ElemType key) {
    int Hi = Hash(key);
    for(int i = 0; i < table.tLength; i++) {
        int index = (Hi + Di[i]) % table.tLength;
        if(table.pList[index] == INF) {
            table.pList[index] = key;
            table.kNum++;
            break;
        }else if(table.pList[index] == key) {
            break;
        }
    }
}


/**
 * 课程版本
 * 例题 4:设计算法在开放地址法解决冲突的哈希表中插入一个关键字 k.要求:先在哈希表中查找关键字 k,
 * 如果关健字 k 已存在则将 k 已存在于表中, 则查找成功, 不再执行插入操作;
 * 如果关键字k不存在于表中, 则查找失败, 执行插入操作, 哈希表中。
 * @param table
 * @param key
 */
void insertKey_handout(HashTable &table, ElemType key) {
    int pos = -1;
    int ret = findKeyIndex_handout(table, key, pos);
    if(ret == 0) {
        table.pList[pos] = key;
        ++table.kNum;
    }
}



/**
 * 例题5:设计算法在开放地址法解决冲突的哈希表中删除关键字 k。
 * 要求:先在哈希表中查找关键字k，如果关键字k已存在于表中，则查找成功，执行删除操作;
 * 如果关键字K 不存在于表中，则查找失败，不执行删除操作。
 * @param table
 * @param key
 */
void deleteKey(HashTable table, ElemType key) {
    int pos;
    int ret = findKeyIndex_handout(table, key, pos);
    if(ret == 1) {
        table.pList[pos] = INF;
        table.kNum--;
    }
}


void destroy(HashTable &table) {
    if(table.pList) {
        free(table.pList);
        table.pList = NULL;
    }
    table.kNum = 0;
}
































