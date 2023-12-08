//
// Created by maicaoboy on 2023/12/5.
//
#include "stdio.h"
#include "stdlib.h"

/**
 * 若定义int a[10];int *p=a;请写出至少3种求数组a第个元素的方式
 */
void Q1(){
    int a[10];
    int *p=a;

    int i = 3;
    //1
    a[i-1];


    //2
    p[i-1];


    //3
    *(p+3-1);


    //
    *(a+3-1);
};


/**
 * (2)如果想通过一个函数获得多个返回值，请至少写出 2种实现方法，并举例说明。
 */
//方法1:将结果存入数组,返回数组
int *Q2_1(){
    int *a = (int*) malloc(sizeof(int)*2);
    a[0] = 1;
    a[1] = 2;
    return a;
}


//方法二:使用结构体
typedef struct{
    int a;
    int b;
}result;

result Q2_2() {
    result a;
    a.a = 1;
    a.b = 2;
    return a;
}

//方法三:使用指针
void Q2_3(int *a, int *b){
    *a = 1;
    *b = 2;
}

//方法四:使用全局变量
int a;
int b;
void Q2_4(){
    a = 1;
    b = 2;
}



/**
* 举例说明结构体和共同体的区别。
 * 结构体中的每个变量使用不同的存储空间,共同体中的每个变量使用同一块存储空间,所以共同体中的变量只能有一个被赋值,
 * 赋值后其他变量的值会被覆盖,结构体则可以对每个变量赋值, 而不会改变其他变量的值
 *
 * 答案:在结构体中各成员有各自的存储空间,一个结构体变量的总长度大于等于各成员的长度之和,
 * 而在联合体中,各成员共享一段存储空间,一个联合变量的长度等于各成员中最长的长度,
*/
union data1 {
    int a;
    char b;
};

struct data2 {
    int a;
    char b;
};

int main() {
    union data1 a;
    a.a = 1;
    a.b = 'a';
    printf("%d\n", a.a);    //此处输出的不是1,而是'a'的ASCII码
    printf("%c\n", a.b);    //此处输出的是'a'

    struct data2 b;
    b.a = 1;
    b.b = 'a';
    printf("%d\n", b.a);    //此处输出的是1
    printf("%c\n", b.b);    //此处输出的是'a'
};
