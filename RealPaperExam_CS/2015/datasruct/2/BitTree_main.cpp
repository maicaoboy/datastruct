//
// Created by xiang on 2023/11/7.
//
#include "BitTree.cpp"

int main() {
    BitTree T = NULL;
    BitTree T1 = NULL;
    BitTree T2= NULL;
    BitNode *node = NULL;
    int length = 0;
    int count = 0;
    ElemType data = 0;
    int height = 0;

    ElemType preOrderArray[] = {1,2,4,5,7,8,3,6};
    ElemType midOrderArray[] = {4,2,7,5,8,1,3,6};
    ElemType postOrderArray[] = {4,2,7,8,2,6,3,1};
    ElemType leverOrderArray[] = {1,2,3,4,5,6,7,8};


    ElemType comPreOrderArray[] = {1,2,4,5,3,6};
    ElemType comInOrderArray[] = {4,2,5,1,6,3};

    /**
     * 测试例题1
     */
    printf("\n*************** 测试1 *********************\n");
//    T = createBitTreePreMiddle(preOrderArray, 0, 7, midOrderArray, 0, 7);
//    printf("先序遍历:");
//    preOrderTraverse(T);
//    printf("\n");
//    printf("中序遍历:");
//    middleOrderTraverse(T);
//    printf("\n");
//
//    printf("层次遍历:");
//    levelOrderTraverse(T);
//    printf("\n");
//
//    freeBitTree(T);





    /**
     * 测试例题2
     */
    printf("\n*************** 测试2 *********************\n");
    T = createBitTreeLevelMiddle(leverOrderArray, 0, 7,midOrderArray, 0, 7);
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");

    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    freeBitTree(T);


    /**
     * 测试例题3
     */
    printf("\n*************** 测试3 *********************\n");
    T = createBitTreeLevelMiddle(leverOrderArray, 0, 7,midOrderArray, 0, 7);
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    count = countBitTree(T);
    printf("树的节点个数为:%d", count);
    printf("\n");

    freeBitTree(T);


    /**
     * 测试例题4
     */
    printf("\n*************** 测试4 *********************\n");
    T = createBitTreeLevelMiddle(leverOrderArray, 0, 7,midOrderArray, 0, 7);
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    count = countLeaf(T);
    printf("树的叶子节点个数为:%d", count);
    printf("\n");

    freeBitTree(T);

    /**
     * 测试例题5
     */
    printf("\n*************** 测试5 *********************\n");
    T = createBitTreeLevelMiddle(leverOrderArray, 0, 7,midOrderArray, 0, 7);
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    count = countNodeDegree1(T);
    printf("树的度为1的节点个数为:%d", count);
    printf("\n");

    freeBitTree(T);


    /**
     * 测试例题6
     */
    printf("\n*************** 测试6 *********************\n");
    T = createBitTreeLevelMiddle(leverOrderArray, 0, 7,midOrderArray, 0, 7);
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    data = 5;
    node = findNodeX(T, data);
    printf("找到节点: %d 的地址为为: %p ", data, node);
    if(node) {
        printf("节点数据为: %d ", node->data);
    }
    printf("\n");

    freeBitTree(T);


    /**
     * 测试例题7
     */
    printf("\n*************** 测试7 *********************\n");
    T = createBitTreeLevelMiddle(leverOrderArray, 0, 7,midOrderArray, 0, 7);
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    height = heightBitTree(T);
    printf("二叉树的高度为:%d", height);
    printf("\n");

    freeBitTree(T);

    /**
     * 测试例题8
     */
    printf("\n*************** 测试8 *********************\n");
    T = createBitTreeLevelMiddle(leverOrderArray, 0, 7,midOrderArray, 0, 7);
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    data = 1;
    height = heightOfNodeX(T, data);
    printf("节点x: %d 的高度为:%d", data, height);
    printf("\n");

    freeBitTree(T);

    /**
     * 测试例题9
     */
    printf("\n*************** 测试9 *********************\n");
    T = createBitTreeLevelMiddle(leverOrderArray, 0, 7,midOrderArray, 0, 7);
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    swapChild(T);

    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");
    freeBitTree(T);


    /**
     * 测试例题 10
     */
    printf("\n*************** 测试10 *********************\n");
    T1 = createBitTreeLevelMiddle(leverOrderArray, 0, 7,midOrderArray, 0, 7);
    printf("先序遍历:");
    preOrderTraverse(T1);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T1);
    printf("\n");
    T2 = createBitTreeLevelMiddle(leverOrderArray, 0, 7,midOrderArray, 0, 7);
//    T2->rchild->rchild->lchild = (BitNode*) malloc(sizeof (BitNode));
    printf("先序遍历:");
    preOrderTraverse(T2);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T2);
    printf("\n");

    int result = isSimilar(T1, T2);
    if(result) {
        printf("相似");
    }else {
        printf("不相似");
    }
    printf("\n");

    freeBitTree(T);



    /**
     * 测试例题 11
     */
    printf("\n*************** 测试11 *********************\n");
    T = createBitTreeLevelMiddle(leverOrderArray, 0, 7,midOrderArray, 0, 7);
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    BitNode *head = createLeafToDuLinkList(T);
    node = head->rchild;
    printf("叶子链表为: ");
    while(node) {
        printf("%d ", node->data);
        node = node->rchild;
    }
    printf("\n");


    //由于改变了叶子节点指针,破坏了树结构,无法正常释放
    //freeBitTree(T);




    /**
     * 测试例题 11
     */
    printf("\n*************** 测试11 *********************\n");
//    T = createBitTreeLevelMiddle(leverOrderArray, 0, 7,midOrderArray, 0, 7);
//    //T = createBitTreePreMiddle(comPreOrderArray, 0, 5,comInOrderArray, 0, 5);
//    printf("先序遍历:");
//    preOrderTraverse(T);
//    printf("\n");
//    printf("中序遍历:");
//    middleOrderTraverse(T);
//    printf("\n");
//
//    result = isCompleteBitTree(T);
//    if(result) {
//        printf("是完全二叉树");
//    }else {
//        printf("不是完全二叉树");
//    }
//
//    freeBitTree(T);


    /**
     * 测试例题 12
     */
    printf("\n*************** 测试12 *********************\n");
    T = createBitTreeLevelMiddle(leverOrderArray, 0, 7,midOrderArray, 0, 7);
    //T = createBitTreePreMiddle(comPreOrderArray, 0, 5,comInOrderArray, 0, 5);
    printf("先序遍历:");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:");
    middleOrderTraverse(T);
    printf("\n");

    T->rchild->lchild = (BitNode*) malloc(sizeof (BitNode));
    T->rchild->lchild->data = 4;
    T->rchild->lchild->lchild = NULL;
    T->rchild->lchild->rchild = NULL;

    result = MaxWidth(T);
    printf("二叉树的最大宽度为:%d", result);

    freeBitTree(T);


}