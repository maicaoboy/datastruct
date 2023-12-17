//
// Created by xiang on 2023/11/8.
// 180行开始
//
#include "BSTree.cpp"

int main() {
    int array[] = {5,3,8,2,67,34,9,13,76,4};
    int length = 10;
    int x;
    int level;
    ElemType key;

    BSTree T = NULL;
    BSTree T1 = NULL;
    BSTree T2 = NULL;
    createBSTree(T, array, length);

    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    freeBSTree(T);


    /**
     * 测试例题 16
     */
    printf("\n*************** 测试16 *********************\n");
    createBSTree(T, array, length);
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    x = 9;
    level = findLevelOfX(T, x);
    printf("%d 所在的层次为: %d", x, level);
    printf("\n");

    freeBSTree(T);


    /**
     * 测试例题 17
     */
    printf("\n*************** 测试17 *********************\n");
    createBSTree(T, array, length);
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    x = 76;
    deleteNodeX(T, x);
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    freeBSTree(T);



    /**
     * 测试例题 18
     */
    printf("\n*************** 测试18 *********************\n");
    createBSTree(T, array, length);
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    key = 50;
    findNodeLessKey(T, key);
    printf("\n");

    freeBSTree(T);


    /**
     * 测试例题 19
     */
    printf("\n*************** 测试19 *********************\n");
    createBSTree(T, array, length);
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    key = 50;
    departBSTree(T, T1, T2, key);
    printf("中序遍历T1:");
    middleOrderTraverse(T1);
    printf("\n");
    printf("中序遍历T2:");
    middleOrderTraverse(T2);
    printf("\n");

    freeBSTree(T1);
    freeBSTree(T2);
    T = NULL;



    /**
     * 测试例题 20
     */
    printf("\n*************** 测试20 *********************\n");
    createBSTree(T, array, length);
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    x = 50;
    deleteNodeLessX(T, x);

    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    freeBSTree(T);







    /**
     * 2020CS-五-3
     */
    printf("\n*************** 测试20 *********************\n");
    createBSTree(T, array, length);
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    x = 3;
    deleteLessThanX(T, x);

    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    freeBSTree(T);







    /**
     * 2019CS-2-2
     */
    printf("\n*************** 测试20 *********************\n");
    createBSTree(T, array, length);
    T->rchild->rchild->lchild->data = 4;
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    x = 4;
    postOrder_X(T, x);

    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    freeBSTree(T);






    /**
     * 2017CS-2-2
     */
    printf("\n*************** 测试21 *********************\n");
    createBSTree(T, array, length);
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    x = 34;
    printf("%d\n",findLevel(T, x, 1));

    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    freeBSTree(T);







    /**
     * 模拟1-4-2
     */
    printf("\n*************** 测试222 *********************\n");
    createBSTree(T, array, length);
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    T->rchild->rchild->data = 3;

    printf("%d\n", isBSTree(T));

    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    freeBSTree(T);






    /**
     * 找到最远的叶子
     */
    printf("\n*************** 测试23 *********************\n");
    createBSTree(T, array, length);
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    T->rchild->rchild->lchild->lchild->lchild = (BSTNode*)malloc(sizeof (BSTNode));
    T->rchild->rchild->lchild->lchild->lchild->data = 100;
    findfarestLeaf_Pre(T, NULL, 1);
    printPath();

    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    freeBSTree(T);




























}
































