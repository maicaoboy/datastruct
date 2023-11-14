//
// Created by maicaoboy on 2023/11/12.
//
#include "CSTree.cpp"
int main () {
    ElemType preArray[] = {1,2,3,4,15,26,27,28};
    ElemType inArray[] = {2,3,4,1,15,27,28,26};
    int length = 8;
    CSTree T = NULL;


    /**
     * 测试0 建立森林,先序遍历,中序遍历
     */
    printf("\n*************** 测试0 *********************\n");
    T = createBitTreePreMiddle(preArray, 0, length - 1,
                               inArray, 0, length - 1);
    printf("先根遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("后根遍历:");
    inOrderTraverse(T);
    printf("\n");

    freeCSTree(T);
































































}