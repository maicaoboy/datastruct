//
// Created by maicaoboy on 2023/10/7.
//
 /*
  * 包含算法9.2 二分查找
  */

#include "Search_Bin.h"
#include "SSTable.h"

#define EQ(a, b) ((a) == (b))
#define LT(a, b) ((a) < (b))
#define LQ(a, b) ((a) <= (b))

int Search_Bin(SSTable ST, KeyType key) {
    int low, high, mid;

    low = 1, high = ST.length;

    while(low <= high) {
        mid = (low + high) / 2;

        if(EQ(key, ST.elem[mid].key)) {
            return mid;
        }else if(LT(key, ST.elem[mid].key)) {
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    return 0;
}
