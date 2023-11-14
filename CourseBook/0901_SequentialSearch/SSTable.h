//
// Created by maicaoboy on 2023/10/7.
//

#ifndef CLION_SSTABLE_H
#define CLION_SSTABLE_H

#include "Status.h"

#define EQ(a, b) ((a) == (b))

typedef int KeyType;

typedef struct {
    KeyType key;
}ElemType;


typedef struct {
    ElemType *elem;         //数据元素存储空间基址,0号元素留空
    int length;             //表长度
} SSTable;

#endif //CLION_SSTABLE_H
