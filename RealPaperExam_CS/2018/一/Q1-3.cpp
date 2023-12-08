//
// Created by maicaoboy on 2023/12/7.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//1.写出 define 与 typedef的区别。(举例并解释)
/**
 * define是简单的字符替换,而typedef是将一种数据类型重命名
 */
#define E1 int      //所有E1字符串会使用int字符串替换
#define A B         //A代表B,即所有字符串B会使用字符串A替换
typedef int E2;      //E2代表int这种数据类型
//typedef A B;         //错误,A不是有效的数据类型


/**
 * 答案:
 * (1)define是一种宏定义,typedef是一种类型定义
 * (2)define是在预编译时进行简单的替换,不做正确性检查,而typedef是咋编译期间进行的类型定义,编译器会做正确性检查
 * (3)例如#define INT int 会使得之后的代码出现INT的dif,将INT替换成int,而typedef int INT则是进行了一种类型定义
 */



void Q2() {
    /**
    * 写出两种判断字符串结束的方法。(举例并解释)
    */
    char s[] = "abcdefg";
    //1判断结尾是不是'\0'
    *s == '\0';                 //字符串以'\0'作为结束,只要遇到'\0'说明字符串已经结束


    //使用字符串长度
    int length = strlen(s);
    char *p = s;
    if(p - s >= length);         //求字符串长度,当遍历超过或等于length时说明已经结束
}



/**
 * Q3
 * 实参为二维数组arr[3][4],则函数的形参形式为(*p)[4],
 * 实参为一维数组arr[3],则函数的形参形式为*p
 * 实参为指针数组*arr[3],则函数的形参形式是*p
 */

void Q3_fun(int array[], int size){
    return;
}


void Q3() {
    int a[10];
    Q3_fun(a, 10);          //可以传入数组,数据类型完全匹配

    int *b = a;
    Q3_fun(b, 10);          //可以传入数组首地址指针
}

int main() {
    int a[10]={0,1};
    for (int i = 0; i < 10; ++i) {
        printf("%d ", a[i]);
    }
}






















