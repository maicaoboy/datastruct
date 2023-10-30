//
// Created by maicaoboy on 2023/10/7.
//

/*
 * 包含算法9.1 顺序查找
 */

#include "SSTable.h"
#include "Search_Seq.h"


int Search_Seq(SSTable ST, KeyType key) {
    int i;

    ST.elem[0].key = key;

    for(i = ST.length; !EQ(ST.elem[i].key, key); i--);

    //i = 0说明没找到
    return i;
}