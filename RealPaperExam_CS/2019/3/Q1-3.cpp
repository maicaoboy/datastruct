//
// Created by maicaoboy on 2023/12/6.
//
#include "stdio.h"
#include "stdlib.h"


/**
 * 1.
* 一个数的平方的层次数等于该数自身的自然数被称为自守数，例5*5=25,25*25=625,9376*9376=87909376。求10000以内的所有自守数。
*/
int isSimilar(int num) {
    int power =  num * num;
    while(num > 0) {
        int num1 = num % 10;
        int num2 = power % 10;
        if(num1 != num2) {
            return 0;
        }
        num /= 10;
        power /= 10;
    }
    return 1;
}

void findNum() {
    for (int i = 0; i < 10000; ++i) {
        if(isSimilar(i)) {
            printf("%d ", i);
        }
    }
}


/**
 * 2.
* 编写一个函数 int judgeM(int a[N][N])，判断给定的函数矩阵a[N][N]是否合上三角矩阵条件。其中N代表 N*N 矩阵。
 * 如果符合上三角矩阵条件返回 1，否则返回 0。上三矩阵的主对角线下方的元素都为9。如下
*/
#define N 32
#define N1 4
int judgeM(int a[N1][N1]) {
    for(int i = 1; i < N1; i++) {
        for(int j = 0; j < i; j++) {
            if(a[i][j] != 0) {
                return 0;
            }
        }
    }
    return 1;
}


/**
 * 3.
 * 请编写函数 void maxCost(struct Consume record[N])，
 * 统计在给定的消费记录 struct Consume record[N]中总消费金额最多的消费项目，输出消费项目名称和对应项目的总消费金额。
 * 需要注意的是，每个项目可能发生多次消费行为，每次消费行为会形成一个消费记录
 */

struct Consume {
    int id;
    unsigned pid;
    char p[100];
    float cost;
};

void swap(struct Consume *s1, struct Consume *s2) {
    struct Consume s;
    s = *s1;
    *s1 = *s2;
    *s2 = s;
}

void maxCost(struct Consume record[N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 1; j < N - i - 1; ++j) {
            if(record[j - 1].pid > record[j].pid) {
                swap(&record[j - 1], &record[j]);
            }
        }
    }

    float sum = 0.0, max = 0.0;
    int slow = 0; int fast = 0,pre = 0,index;
    while(slow < N) {
        if(record[pre].pid == record[fast].pid) {
            pre = fast;
            fast++;
            if(fast == N){
                break;
            }
        }else {//slow-pre之间找到一个消费类别的记录
            for (int i = slow; i <= pre; ++i) {
                sum += record[i].cost;
            }
            if(sum > max) {
                max = sum;
            }
            index = slow;
            slow = fast;
        }
    }
    for (int i = slow; i <= pre; ++i) {
        sum += record[i].cost;
    }
    if(sum > max) {
        max = sum;
    }
    printf("%d %s %f", record[index].pid, record[index].p, max);
}

void maxCost1(struct Consume record[N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 1; j < N - i - 1; ++j) {
            if(record[j - 1].pid > record[j].pid) {
                swap(&record[j - 1], &record[j]);
            }
        }
    }

    int index = 0;
    int pre = 0;
    float sum = 0.0, max = 0.0;
    for (int i = 0; i < N; ++i) {
        if(record[i].pid == record[pre].pid) {
            sum += record[i].cost;
        }else {
            pre = record[i].pid;
            if(sum > max) {
                max = sum;
                index = pre;
            }
            sum = record[i].cost;
        }
        pre = i;
    }
    if(sum > max) {
        max = sum;
    }
    printf("%d %s %f", record[index].pid, record[index].p, max);
}

int main() {
    struct Consume record[N] = {
            {1, 1, "a", 1.0},
            {2, 1, "a", 2.0},
            {3, 2, "b", 3.0},
            {4, 2, "b", 4.0},
            {5, 3, "c", 5.0},
            {6, 3, "c", 6.0},
            {7, 4, "d", 7.0},
            {8, 4, "d", 8.0},
            {9, 5, "e", 9.0},
            {10, 5, "e", 10.0},
            {11, 6, "f", 11.0},
            {12, 6, "f", 12.0},
            {13, 7, "g", 13.0},
            {14, 7, "g", 14.0},
            {15, 8, "h", 15.0},
            {16, 8, "h", 16.0},
            {17, 9, "i", 17.0},
            {18, 9, "i", 18.0},
            {19, 10, "j", 19.0},
            {20, 10, "j", 20.0},
            {21, 11, "k", 21.0},
            {22, 11, "k", 22.0},
            {23, 12, "l", 23.0},
            {24, 12, "l", 24.0},
            {25, 13, "m", 25.0},
            {26, 13, "m", 26.0},
            {27, 14, "n", 27.0},
            {28, 14, "n", 28.0},
            {29, 15, "o", 29.0},
            {30, 15, "o", 3.0},
            {31, 16, "p", 31.0},
            {32, 16, "p", 19.0}};
    maxCost1(record);


    printf("\n");
    int M[N1][N1] = {
            {1,2,3,4},
            {0,5,6,7},
            {0,0,8,9},
            {0,0,0,10}
    };
    printf("%d\n", judgeM(M));
    findNum();
    return 0;
}






































