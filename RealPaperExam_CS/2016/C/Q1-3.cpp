//
// Created by maicaoboy on 2023/12/9.
//
#include "stdio.h"
#include "stdlib.h"


/**
* 编写程序:求s=1 + 2x3 + 4x5x6 + 7x8x9x10 + 11x12x13x14x15 +...求前 n 项之和，由键盘输入数据 n。
*/

int Q1() {
    int n;
    scanf("%d", &n);
    int k = 1;
    int ret = 0;
    for (int i = 1; i <= n; ++i){
        int sum = 1;
        for (int j = 1; j <= i; k++, j++) {
            sum *= k;
        }
        ret += sum;
    }
    return ret;
}



/**
 * 某歌咏比赛中,有 8 个评委对 20 位选手进子评分,选手按 1~20 号进行编号，
 * 每个评委给出 1~10的分数，在统计分数时要除去一个最低分和最高分，
 * 计算出其他评委给出分数的平均分作为选手的最后得分。编写程序实现以下功能:
 * 评委输入,按评分输出得分最高的 3 位选手的编号和分数,要求求程序执行时间最少。
 */

typedef struct {
    int id;
    int score[8];
    float ave;
}score;

void Q() {
    score scores[20];
    for (int i = 0; i < 20; ++i) {
        scores[i].id = i + 1;
        float min = 11.0;
        float max = -1.0;
        float fen;
        float sum;
        for (int j = 0; j < 8; ++j) {
            scanf("%f", &fen);
            sum += fen;
            if(fen < min) {
                min = fen;
            }else if(fen > max) {
                max = fen;
            }
            scores[i].score[j] = fen;
        }
        sum -= min;
        sum-= max;
        scores[i].ave = sum /= 6;
        if(i >= 2) {    //对前三位排序
            for (int j = 0; j < 3; ++j) {
                if(scores[i].ave > scores[j].ave) {
                    score temp;
                    temp = scores[i];
                    scores[i] = scores[j];
                    scores[j] = temp;
                }
            }
        }
    }
    for(int i = 0; i < 3; i++) {
        printf("%d ", scores[i].id);
        for (int j = 0; j < 8; ++j) {
            printf("%d ", scores[i].score[j]);
        }
        printf("\n");
    }
}



/**
 * 编写程序，查找给定字符在字符串中首次出现的位置。要求:不使用有关字符串处理的库函数
 * 主函数中键盘输入字符串以及查找的字符调用子函数;
 * 子函数完成查找任务，如果字符串中包含所查找的字符，则返回该字符在字符串首次出现的位置，否则返回 0。
 */

int Q3(char str[1025], char rex[100]) {
    int flag;
    for (int i = 0; str[i] != '\0'; ++i) {
        flag = 1;
        for (int j = 0; rex[j] != '\0'; ++j) {
            if(rex[j] != str[i + j]) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            return 1;
        }
    }
    return 0;
}

void Q3_main() {            //题目要求查找字符
    char str[1025] = "";
    char rex[100] = "";

    printf("请输入原始字符串(#结束):");
    char c;
    for (int i = 0;; ++i) {
        scanf("%c", &c);
        if(c == '#'){
            str[i] = '\0';
        }else {
            str[i] = c;
        }
    }

    printf("请输入匹配字符串(#结束):");
    for (int i = 0;; ++i) {
        scanf("%c", &c);
        if(c == '#'){
            rex[i] = '\0';
        }else {
            rex[i] = c;
        }
    }

    int ret = Q3(str, rex);
}
































