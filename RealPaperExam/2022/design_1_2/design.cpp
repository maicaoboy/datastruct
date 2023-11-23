//
// Created by maicaoboy on 2023/11/23.
//
#include "stdio.h"
#include "stdlib.h"
/**
 * 编写程序计算1/1!+1/2!+1/3!....1/n!,n由键盘输入
 */
void calculate() {
    int n;
    scanf("%d", &n);
    double sum = 0.0;
    int jie = 1;
    for (int i = 1; i <= n; ++i) {
        sum += (1.0 / (jie * i));
    }
    printf("%lf\n", sum);
}





int main() {
    calculate();
}