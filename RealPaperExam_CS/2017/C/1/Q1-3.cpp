//
// Created by maicaoboy on 2023/12/8.
//
#include "stdio.h"
#include "stdlib.h"

/**
* 指针 p 指向了数组 a，求数组第 i 个元素的三种表示方法
*/

void Q1() {
    int a[10];
    int  *p = a;

    int i = 3;

    //1
    p[i - 1];


    //2
    a[i - 1];


    //3
    *(p + i - 1);


    //4

    *(a + i - 1);
}


/**
 * 函数的形参为指针，求对应的实参的两种表示方法。
 * @param a
 */

void Q2_fun(int *a){}

void Q2() {
    int a;

    Q2_fun(&a);

    int *b;
    Q2_fun(b);
};


/**
* 函数声明的作用，在什么情况下自定义函数不需要函数声明?
*/

/**
* 函数声明可以声明一个函数的形式,但可以不需要实现一个函数的内容,是的可以在该函数定义之前(指代码顺序)使用该函数
 * 只需在函数定义之后使用该函数就可以不用函数声明
*/
