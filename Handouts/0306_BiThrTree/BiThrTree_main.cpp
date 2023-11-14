//
// Created by xiang on 2023/11/9.
//
#include "BiThrTree.cpp"
int main() {
    int array[] = {5,3,8,2,67,34,9,13,76,4};
    int length = 10;
    int x;
    int level;
    ElemType key;
    int unBanlance;

    BiThrTree T = NULL;
    BiThrTree T1 = NULL;
    BiThrTree T2 = NULL;


    /**
     * 测试23/24
     */
    printf("\n*************** 测试23/24 *********************\n");
    createBiTree(T, array, length);
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    preThreading(T);
    traversePreThrTree(T);
    printf("\n");

//    freeBiThrTree(T);


/**
     * 测试23/24
     */
    printf("\n*************** 测试23/24 *********************\n");
    T = NULL;
    createBiTree(T, array, length);
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    inThreading(T);
    traverseInThrTree(T);
    printf("\n");


//    freeBiThrTree(T);







}