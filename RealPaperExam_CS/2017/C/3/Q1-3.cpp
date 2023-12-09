//
// Created by maicaoboy on 2023/12/8.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char *numToStr(char numStr[20], int num) {  //将数字转化为字符串
    char *ptr = numStr;
    int length;
    while (num != 0) {
        *ptr++ = num % 10 + '0';
        num /= 10;
        length++;
    }
    *ptr = '\0';
    int i = 0, j = length - 1;
    char temp;
    while(i < j) {
        temp = numStr[i];
        numStr[i++] = numStr[j];
        numStr[j--] = temp;
    }
}


void intToString(int num, char str[], int* length) {
    // 初始化长度为0
    *length = 0;

    // 处理0的情况
    if (num == 0) {
        str[(*length)++] = '0';
        str[*length] = '\0';
        return;
    }

    // 处理负数
    if (num < 0) {
        str[(*length)++] = '-';
        num = -num;
    }

    // 逆序生成每一位的字符
    while (num > 0) {
        int digit = num % 10;
        str[(*length)++] = digit + '0';
        num /= 10;
    }

    // 反转字符串
    int i, j;
    for (i = 0, j = *length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    // 添加字符串结束符
    str[*length] = '\0';
}

char *multi() {                                 //乘法口诀
    char numStr[20];
    char *str = (char*) malloc(sizeof(char) * 4096);
    char *ptr = str;
    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j <= i; ++j) {
            numToStr(numStr, i);
            char *strOfNum = numStr;
            while(*numStr != '\0') {
                *ptr++ = *strOfNum++;
            }
            *ptr++ = '*';
            numToStr(numStr, j);
            strOfNum = numStr;
            while(*numStr != '\0') {
                *ptr++ = *strOfNum++;
            }
            *ptr++ = '=';
            numToStr(numStr, i * j);
            strOfNum = numStr;
            while(*numStr != '\0') {
                *ptr++ = *strOfNum++;
            }
            *ptr++ = ' ';
        }
        *ptr++ = '\n';
    }
    *ptr = '\0';
    return str;
}


void wangshu() {
    int num = 0;
    int temp;
     scanf("%d", &num);
     int numArr[10];
     int len = 0;
     temp = num;
     while(temp > 0) {
         numArr[len++] = temp % 10;
         temp /= 10;
     }
     int ret = 1;
     for(int i = 0, j = len - 1; i < j; i++,j--) {
         if(numArr[i] != numArr[j]) {
             ret = 0;
             break;
         }
     }
     int sum = 0;
     temp = num;
    for (int i = 0; i < temp; ++i){
        if(temp % i == 0) {
            sum += i;
        }
    }
    if(sum == num &&ret) {
        ret = 1;
    }
    printf("%d", ret);
}




typedef struct Student {
    int studentID;          //学号
    float score;            //成绩
    struct Student *next;
}LinkNode, *LinkList;


void createStudent(LinkList &L) {
    int studentID;
    float score;
    printf("请依次输入各个学生的学号,成绩");
    L = (LinkNode*) malloc(sizeof (LinkNode));
    L->next = NULL;
    L->studentID = 0;
    L->score = 0.0;
    while(1) {
        scanf("%d %f", &studentID, &score);
        if(studentID == 0) {
            break;
        }else {
            LinkNode *node = (LinkNode*)malloc(sizeof (LinkNode));
            node->studentID = studentID;
            node->score = score;
            node->next = L->next;
            L->next = node;
        }
    }
}



void tongji(LinkList L) {
    LinkNode *node = L->next;
    int count[5] = {0};
    while(node != NULL) {
        if(node->score < 60.00001) {
            count[0]++;
        }else if(node->score >= 59.99999 && node->score < 69.99999) {
            count[1]++;
        }else if(node->score >= 69.99999 && node->score < 79.99999) {
            count[2]++;
        }else if(node->score >= 79.99999 && node->score < 89.99999) {
            count[3]++;
        }else if(node->score >= 89.99999) {
            count[4]++;
        }
        node = node->next;
    }
    printf("人数统计:\n60以下:%d\n60-69:%d\n70-79:%d\n80-89:%d\n90-100:%d\n", count[0], count[1], count[2], count[3], count[4]);
}













