//
// Created by maicaoboy on 2023/9/1.
//
#include "stdio.h"
#include "stdlib.h"
#include "SSTable.h"
#include "Search_Seq.h"


int main(int argc, char** argv) {
    SSTable ST;
    int i;
    int length = 11;
    KeyType key;

    int index;

    ST.elem = malloc(sizeof(ElemType) * length);
    ST.length = length - 1;

    for(i = ST.length; i > 0; i--) {
        ST.elem[i].key = i;
    }

    key = 3;

    index = Search_Seq(ST, key);
    if(index == 0) {
        printf("未找到元素: %d .", key);
    }else{
        printf("找到元素: %d 的位置: %d .", key, index);
    }
}
