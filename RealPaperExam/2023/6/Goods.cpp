//
// Created by maicaoboy on 2023/11/23.
//
#include "stdio.h"

struct Goods {
    int id;
    char name[100];
    float price;
    int remain;
};



void sum(struct Goods record[20]) {
    int length = 20;
    int count = 0;
    float sum = 0.0;

    int curSize = 0;    //已排序长度

    for (int i = 0; i < length; ++i) {
        Goods good = record[i];
        int index = curSize - 1;
        while(index >= 0 && good.id < record[index].id) {
            record[index + 1] = record[index];
            index--;
        }
        record[index + 1] = good;

        if(index < 0 || record[index].id != good.id) {
            count++;
            sum += good.price;
        }
        curSize++;
    }
    printf("种类:%d, 种类:%f\n", count, sum);
}



int main() {
    Goods records[20] = {1, "apple", 3.0, 2, 1, "apple", 3.0, 100, 2, "lizi", 4.0, 7,1, "apple", 3.0, 2, 1, "apple", 3.0, 100, 2, "lizi", 4.0, 7,1, "apple", 3.0, 2, 1, "apple", 3.0, 100, 2, "lizi", 4.0, 7,1, "apple", 3.0, 2, 1, "apple", 3.0, 100, 2, "lizi", 4.0, 7,1, "apple", 3.0, 2, 1, "apple", 3.0, 100, 2, "lizi", 4.0, 7,1, "apple", 3.0, 2, 1, "apple", 3.0, 100, 2, "lizi", 4.0, 7,1, "apple", 3.0, 2, 1, "apple", 3.0, 100};
    sum(records);
};
