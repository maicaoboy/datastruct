//
// Created by maicaoboy on 2023/12/12.
//
#include "stdio.h"
#include "stdlib.h"

/**
 * 函数 deletest的功能是将在字符串中出现，而未在字符串中出现的字符形成一个新的字符串放在中，
 * u中字符按原来字符串中的字符顺序排列，不去掉重复字符。例如，当s=”112345i=”2467”时，u中的字符串为”1135”。
 * @param s
 * @param t
 */
void deleteStr(char *s, char *t, char *u) {
    char *ptr = u;
    char *ptr1;
    char *ptr2;
    for (ptr1 = s; *ptr1 != '\0'; ++ptr1) {
        for (ptr2 = t; *ptr2 != '\0'; ptr2++){
            if(*ptr1 == *ptr2) {
                break;
            }
        }
        if(*ptr2 == '\0') {
            *ptr++ = *ptr1;
        }
    }
    *ptr = '\0';
}



struct Consume {
    int id;
    unsigned pid;
    char p[100];
    float cost;
};

#define N 100

void swap(struct Consume *s1, struct Consume *s2) {
    Consume temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void maxCost(struct Consume record[N]){
    int maxIndex;
    float maxCost;
    int minIndex;
    float minCost;
    int preIndex = 0;
    float sum;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if(record[i].pid < record[j].pid) {
                swap(&record[i], &record[j]);
            }
        }
    }

    sum = 0;
    for (int i = 0; i < N; ++i) {
       if(record[i].pid == record[preIndex].pid) {
           sum += record[i].cost;
       } else {
           if(sum > maxCost) {
               maxCost = sum;
               maxIndex = preIndex;
           }else if(sum < minCost) {
               minCost = sum;
               minIndex = preIndex;
           }
           sum = record[i].cost;
       }
       preIndex = i;
    }
    printf("最多:pid:%d, name:%f", record[maxIndex].pid, record[maxIndex].p);
    printf("最多:pid:%d, name:%f", record[minIndex].pid, record[minIndex].p);
}



















void operateNum() {
    int num;
    scanf("%d", &num);
    if(num % 11 == 0) {
        printf("%d\n", num);
    }else {
        FILE *file = fopen("D:\\output.dat", "w");
        if(file == NULL) return;
        int numArray[4] = {0};
        for (int i = 3; i >= 0; --i) {
            numArray[i] = num % 10;
            num /= 10;
        }
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    for (int l = 0; l < 4; ++l) {
                        if(i+j+k+l != 6) continue;
                        int sum = numArray[i] * 1000 + numArray[j] * 100 + numArray[k] * 10 + numArray[l] * 1;
                        if(sum % 11 == 0) {
                            if(i == j && j == k  && k== l && l == 3) {
                                fprintf(file, "%d", sum);
                            }else {
                                fprintf(file, "%d,", sum);
                            }
                        }
                    }
                }
            }
        }
        fclose(file);
        file = fopen("D:\\output.dat", "r");
        if(file == NULL) return;
        int maxNum = 0;
        int currentNum;
        while(fscanf(file, "%d,", &currentNum) != EOF) {
            if (currentNum > maxNum) {
                maxNum = currentNum;
            }
        }
        fclose(file);

        // 输出最大数
        printf("\nMax number in the file: %d\n", maxNum);
    }
}


int main() {
    //operateNum();
    char *str1 = "dbasjnfdsssscvwdadsfewaagrhhhwesfrhtrejbsc";
    char *str2 = "fhjbs";
    char u[1014] = "";
    deleteStr(str1, str2, u);
    printf(u);
}