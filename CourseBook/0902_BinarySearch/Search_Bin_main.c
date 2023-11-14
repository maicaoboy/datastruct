//
// Created by maicaoboy on 2023/10/7.
//
#include "stdio.h"
#include "stdlib.h"
#include "SSTable.h"
#include "Search_Bin.h"


void InitSSTable(SSTable *table, int size, KeyType keys[]);

int main(int argc, char** argv) {
    SSTable ST;
    int i, index, key;
    KeyType keys[] = {5, 13, 19, 21, 37, 56, 64, 75, 80, 88, 92};
    int size = sizeof(keys) / sizeof(keys[0]);

    InitSSTable(&ST, size, keys);



    // 打印初始化后的表
    printf("SSTable初始化完成，长度为：%d\n", ST.length);
    printf("key序列为：");
    for (i = 1; i <= ST.length; i++) {
        printf("%d ", ST.elem[i].key);
    }
    printf("\n");

    //二分查找
    key = 21;
    index = Search_Bin(ST, key);
    if(index == 0) {
        printf("未找到元素: %d .", key);
    }else{
        printf("找到元素: %d 的位置: %d .", key, index);
    }

    // 释放内存
    free(ST.elem);

    return 0;
}

// 初始化SSTable
void InitSSTable(SSTable *table, int size, KeyType keys[]) {
    int i;
    // 为elem分配内存空间，包括额外的0号元素位置
    table->elem = (ElemType *)malloc((size + 1) * sizeof(ElemType));
    if (table->elem == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }

    // 初始化表长度
    table->length = size;

    // 初始化key序列，从下标1开始，0号元素留空
    for (i = 0; i < size; i++) {
        table->elem[i + 1].key = keys[i];
    }
}