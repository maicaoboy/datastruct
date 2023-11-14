//
// Created by maicaoboy on 2023/10/22.
//
#include "stdlib.h"
#include "stdio.h"
#include "../../Status/Status.h"

#define MAX_SIZE 100
#define INCRE_SIZE 10




/**
 * 例题 01
 * 创建一个顺序表
 */

typedef struct SqList{
    int *pList;
    int length;
    int size;
} SqList;


void initial(SqList &L) {
    L.pList = (int*) malloc(sizeof(int) * MAX_SIZE);
    L.length = 0;
    L.size = MAX_SIZE;
}


/**
 * 例题 02
 * 从顺序表删除第 i 个元素
 * @param L             需要删除元素的顺序表
 * @param ith           第 i 个元素,i从1开始计数
 */
Status deleteIthItem(SqList &L, int ith, int &e) {
    if(ith < 1 || ith > L.length) {
        return FALSE;
    }

    e = L.pList[ith - 1];
    for(int i = ith; i < L.length; i++) {
        L.pList[i - 1] = L.pList[i];
    }

    L.length--;

    return TRUE;
}

/**
 * 例题 03
 * 在ith前插入元素e
 * @param L         要插入的顺序表
 * @param ith       在第ith个元素前插入
 * @param e         要插入的元素e
 * @return          插入成功True,插入失败FALSE
 */
Status insert(SqList &L, int ith, int e) {
    int i;
    if(ith < 0 || ith > L.length) {
        return FALSE;
    }

    if(L.length == L.size) {
        int *p = (int *) realloc(L.pList, sizeof(int)*(L.size + INCRE_SIZE));
        if(p == NULL) {
            return FALSE;
        }else {
            L.pList = p;
            L.size += INCRE_SIZE;
        }
    }

    for(i = L.length; i >= ith; i--) {
        L.pList[i] = L.pList[i - 1];
    }
    L.pList[i] = e;
    L.length++;

    return TRUE;
}


/**
 * 例题 04
 * 从顺序表删除最小的元素, 空出的元素由最后一个元素填充
 * @param L         需要操作的顺序表
 */
void deleteMin(SqList &L) {
    int min = 0;
    for(int i = 1; i < L.length; i++) {
        if(L.pList[i] < L.pList[min]) {
            min = i;
        }
    }

    L.pList[min] = L.pList[L.length - 1];
    L.length--;
}



/**
 * 例题 05
 * 在无序顺序表中删除值在s和t之间的所有元素
 * @param L     需要操作的顺序表
 * @param s     区间低值
 * @param t 区间高值
 */
void deleteElem(SqList &L, int s, int t) {
    int index = 0;
    for(int i = 0; i < L.length; i++) {
        if(L.pList[i] < s || L.pList[i] > t) {
            L.pList[index++] = L.pList[i];
        }
    }
    L.length = index;
}


/**
 * 例题 06
 * 在非递减顺序表中删除值在区间[s,t]的所有元素
 * @param L     要修改的顺序表
 * @param s     区间低值
 * @param t     区间高值
 */
void deleteELemOrder(SqList &L, int s, int t) {
    int low, high;
    for(low = 0; low , L.length; low++) {
        if(L.pList[low] >= s) {
            break;
        }
    }

    for(high = L.length - 1; high >= low; high--) {
        if(L.pList[high] <= t) {
            break;
        }
    }

    if(low > high) {
        return;
    }

    int k = high - low + 1;
    for(int i = 0; high + i + 1 < L.length; i++) {
        L.pList[low + i] = L.pList[high + i + 1];
    }

    L.length -= k;
}

/**
 * 例题 07
 * 删除非递减顺序表L中的重复元素
 * @param L     需要操作的顺序表
 */
void deleteELemRepeat(SqList &L) {
    int cur = 0;
    for(int i = 1; i < L.length; i++) {
        if(cur == 0 || L.pList[cur] != L.pList[i]) {
            L.pList[++cur] = L.pList[i];
        }
    }
    L.length = cur + 1;
}


/**
 * 例题 8_1
 * 顺序表A和B的元素个数分别为m和n,表A升序排序,表B降序排序,两个表都不存在相同的元素
 * 将两表合并,两表的元素升序存储到C中
 * note: 最小值法
 * @param A
 * @param B
 * @param C
 */
void merge_1(SqList &A, SqList &B, SqList &C) {
    C.length = 0;
    C.size = A.length + B.length;
    C.pList = (int *) malloc(sizeof(int) * C.size);

    int i = 0;
    int j = B.length - 1;


    while(i < A.length && j >= 0) {
        if(A.pList[i] <= B.pList[j]) {
            C.pList[C.length++] = A.pList[i++];
        }else {
            C.pList[C.length++] = B.pList[j--];
        }
    }

    while(i < A.length) {
        C.pList[C.length++] = A.pList[i++];
    }

    while(j >= 0) {
        C.pList[C.length++] = B.pList[j--];
    }

    free(A.pList);
    A.length = 0;
    A.size = 0;

    free(B.pList);
    B.length = 0;
    B.size = 0;
}


/**
 * 例题 8_2
 * 顺序表A和B的元素个数分别为m和n,表A升序排序,表B降序排序,两个表都不存在相同的元素
 * A有 m+n 个存储空间,将A B两表合并,两表的元素升序存储到A中
 * note:最大值法
 * @param A
 * @param B
 */
void merge_2(SqList &A, SqList &B) {
    int i = A.length - 1;
    int j = 0;
    int cur = A.length + B.length - 1;

    while(i >= 0 && j < B.length) {
        if(A.pList[i] >= B.pList[j]) {
            A.pList[cur--] = A.pList[i--];
        }else {
            A.pList[cur--] = B.pList[j++];
        }
    }

    while(j < B.length) {
        A.pList[cur--] = B.pList[j++];
    }

    A.length = A.length + B.length;
    B.length = 0;
}


/**
 *
 * 例题 8_3
 * 顺序表A和B的元素个数分别为m和n,表A升序排序,表B降序排序,两个表都不存在相同的元素
 * 表A前r个元素递增有序,而表A中后 n-r 个元素递减有序,将A进行升序排列
 * @param A
 */
void sort(SqList &A) {
    int mid = 0;

    while(A.pList[mid] <= A.pList[mid + 1]) {
        mid++;
    }

    for(; mid < A.length - 1; mid++) {
        int e = A.pList[mid + 1];
        int j = mid;
        while(A.pList[j] > e && j >= 0) {
            A.pList[j + 1] = A.pList[j];
            j--;
        }
        A.pList[j + 1] = e;
    }
}


/**
 * 给当两个非空集合 A 和 B ,分别用升序顺序表 La 和 Lb 存储,设计算法求解 A ∩ B
 * @param A
 * @param B
 */
void intersection(SqList &La, SqList&Lb) {
    int i = 0, j = 0, cur = 0;
    while(i < La.length && j < Lb.length) {
        if(La.pList[i] < Lb.pList[j]) {
            i++;
        }else if(La.pList[i] > Lb.pList[j]) {
            j++;
        }else {
            La.pList[cur] = La.pList[i];
            i++;
            j++;
            cur++;
        }
    }
    La.length = cur;
}


/**
 * 给定两个非空集合A和B,分别用升序顺序表La和Lb存储,设计算法求解A-B
 * @param La
 * @param Lb
 */
void difference(SqList &La, SqList &Lb) {
    int i = 0, j = 0, cur = 0;
    while(i < La.length && j < Lb.length) {
        if(La.pList[i] < Lb.pList[j]) {
            La.pList[cur] = La.pList[i];
            i++;
            cur++;
        }else if(La.pList[i] > Lb.pList[j]) {
            j++;
        }else {
            i++;
            j++;
        }
    }

    while(i < La.length) {
        La.pList[cur++] =La.pList[i++];
    }

    La.length = cur;
}


/**
 * 例题 11
 * 设计算法逆置顺序表L
 * @param L 要逆置的顺序表
 */
void reverse(SqList L) {
    int i = 0, j = L.length - 1;

    while(i < j) {
        int temp = L.pList[i];
        L.pList[i] = L.pList[j];
        L.pList[j] = temp;
        i++;
        j--;
    }
}



void reverse_qu(SqList L, int i, int j) {
    while(i < j) {
        int temp = L.pList[i];
        L.pList[i] = L.pList[j];
        L.pList[j] = temp;
        i++;
        j--;
    }
}

/**
 * 循环左移
 * @param L
 * @param r     循环左移r位
 */
void left_r(SqList L, int r) {
    reverse_qu(L, 0, L.length - 1);
    reverse_qu(L, 0, L.length - r - 1);
    reverse_qu(L, L.length - r, L.length - 1);

}






























