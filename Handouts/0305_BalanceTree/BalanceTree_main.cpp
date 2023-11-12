//
// Created by xiang on 2023/11/9.
//
#include "BalanceTree.cpp"
int main() {
    int array[] = {5,3,8,2,67,34,9,13,76,4};
    int length = 10;
    int x;
    int level;
    ElemType key;
    int unBanlance;

    BSTree T = NULL;
    BSTree T1 = NULL;
    BSTree T2 = NULL;


    /**
     * 测试0 建立AVL
     */
    printf("\n*************** 测试0 *********************\n");
    createBalanceTree(T, array, length);
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    freeBSTree(T);


    /**
     * 测试例题 21
     */
    printf("\n*************** 测试21 *********************\n");
//    createBSTree(T, array, length);
    createBalanceTree(T, array, length);
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    unBanlance = 0;
    calculateBF(T, unBanlance);
    printf("不平衡节点个数为: %d", unBanlance);


    freeBSTree(T);


    /**
     * 测试例题 22
     */
    printf("\n*************** 测试22 *********************\n");
//    createBalanceTree(T, array, length);
    createBSTree(T, array, length);
    unBanlance = 0;
    calculateBF(T, unBanlance);
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    int height = countHeightWithBF(T);
    printf("高度为: %d", height);


    freeBSTree(T);




}