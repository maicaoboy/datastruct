//
// Created by maicaoboy on 2023/11/12.
//
#include "CSTree.cpp"
int main () {
    ElemType preArray[] = {1,2,4,5,6,3,7};
    ElemType inArray[] = {4,5,6,2,7,3,1};
    int length = 7;
    int x;
    int level;
    ElemType key;
    int unBanlance;
    int count;

    CSTree T = NULL;
    CSTree T1 = NULL;
    CSTree T2 = NULL;


    /**
     * 测试0 建立树,先根遍历,后根遍历
     */
    printf("\n*************** 测试0 *********************\n");
    T = createBitTreePreMiddle(preArray, 0, length - 1,
                               inArray, 0, length - 1);
    printf("先根遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("后根遍历:");
    postOrderTraverse(T);
    printf("\n");

    freeCSTree(T);



    /**
     * 测试27
     */
    printf("\n*************** 测试27 *********************\n");
    T = createBitTreePreMiddle(preArray, 0, length - 1,
                               inArray, 0, length - 1);
    printf("先根遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("后根遍历:");
    postOrderTraverse(T);
    printf("\n");

    count = countCSTreeLeaf(T);
    printf("树的叶子节点有 %d 个", count);
    printf("\n");
    count = getLeafsSum(T);
    printf("树的叶子节点有 %d 个", count);
    printf("\n");

    freeCSTree(T);




    /**
     * 测试28
     */
    printf("\n*************** 测试28 *********************\n");
    T = createBitTreePreMiddle(preArray, 0, length - 1,
                               inArray, 0, length - 1);
    printf("先根遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("后根遍历:");
    postOrderTraverse(T);
    printf("\n");

    count = degree(T);
    printf("树的度为 %d ", count);
    printf("\n");

    freeCSTree(T);



    /**
     * 测试29
     */
    printf("\n*************** 测试29 *********************\n");
    T = createBitTreePreMiddle(preArray, 0, length - 1,
                               inArray, 0, length - 1);
    printf("先根遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("后根遍历:");
    postOrderTraverse(T);
    printf("\n");

    count = depth(T);
    printf("树的深度为 %d ", count);
    printf("\n");

    freeCSTree(T);










    //中序遍历森林中每一棵树的所有子树,然后再访问第一棵树的根节点,最后中序遍历森林中其余



















































}