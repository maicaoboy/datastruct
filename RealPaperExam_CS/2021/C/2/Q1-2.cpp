//
// Created by maicaoboy on 2023/12/8.
//
#include <stdio.h>
#include <stdlib.h>

/**
* Q1
 *
*/

#define N 30

struct score {
    char number[10];    //学号
    char name[8];       //姓名
    char level;         //成绩等级A-E
};


void swap(score *score1, score *score2) {

}

/**
 * 输出人数和等级
 * 算法思想:先按level关键字排序,之后遍历数组即可查找出相同等级的人数
 * @param record
 */
void summary(struct score record[N]) {
    int num[5] = {0};
    for (int i = 0; i < N; ++i){
        for (int j = 1; j < N; ++j) {
            if(record[j - 1].level > record[j].level) {
                swap(&record[j - 1], &record[j]);
            }
        }
    }
    for (int i = 0; i < N; ++i){
        num[record[i].level - 'A']++;
    }
    int pre = -1;
    for (int i = 0; i < N; ++i){
        if(i == 0) {
            printf("%c:%d人 %s,", record[i].level, num[record[i].level - 'A'], record[i].name);
        }else if(record[i].level == record[pre].level && i != 0) {
            printf("%s,", record[i].name);
        }else {
            printf("%c:%d人 %s,", record[i].level, num[record[i].level - 'A'], record[i].name);
        }
        pre = i;
    }
}



/**
* 将字符串的字母按照ASCII码值从小到大进行排序并删除重复字符后输出
*/
void sortChar() {
    char str[1025];
    char c = 'a';
    int len = 0;
    printf("输入一段字符串,以'#'结束");
    for(int i = 0; len < 1024; i++) {
        scanf("%c", &c);
        if(c != '#') {
            for (int j = 0; j < len; ++j) {
                if(str[j] == c) {
                    continue;
                }
            }
        }else {
            str[len] = '\0';
            break;
        }
        str[len++] = c;
    }
    str[len] = '\0';
    printf("%s ", str);
}



int main() {

}





































