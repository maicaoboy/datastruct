//
// Created by maicaoboy on 2023/11/12.
//
#include "CSTree.cpp"
int main () {
    ElemType preArray[] = {1,2,3,4,15,26,27,28};
    ElemType inArray[] = {2,3,4,1,15,27,28,26};
    int length = 8;
    int x;
    int level;
    ElemType key;
    int unBanlance;
    int count;

    CSTree T = NULL;
    CSTree T1 = NULL;
    CSTree T2 = NULL;


    /**
     * 测试0 建立森林,先序遍历,中序遍历
     */
    printf("\n*************** 测试0 *********************\n");
    T = createBitTreePreMiddle(preArray, 0, length - 1,
                               inArray, 0, length - 1);
//    CSTNode *node = (CSTNode*)malloc(sizeof(CSTNode));
//    node->data = -1;
//    node->firstChild = T;
//    node->nextSibling = NULL;
//    T = node;
    printf("先根遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("后根遍历:");
    inOrderTraverse(T);
    printf("\n");

    freeCSTree(T);














    //中序遍历森林中每一棵树的所有子树,然后再访问第一棵树的根节点,最后中序遍历森林中其余



















































}