//
// Created by xiang on 2023/11/8.
// 310行开始
//
#include "stdio.h"
#include "stdlib.h"
#define ElemType int

typedef struct BSTNode {
    ElemType data;
    struct BSTNode *lchild;
    struct BSTNode *rchild;
    struct BSTNode *parent;
    int level;
}BSTNode, *BSTree;

void visit(BSTNode *node) {
    printf("%d ", node->data);
}

/**
 * 先序遍历
 * @param T
 */
void preOrderTraverse(BSTree T) {
    if(T == NULL) {
        return;
    }
    visit(T);
    preOrderTraverse(T->lchild);
    preOrderTraverse(T->rchild);
}


/**
 * 中序遍历
 * @param T
 */
void middleOrderTraverse(BSTree T) {
    if(T == NULL) {
        return;
    }
    middleOrderTraverse(T->lchild);
    visit(T);
    middleOrderTraverse(T->rchild);
}


/**
 * 后序遍历
 * @param T
 */
void postOrderTraverse(BSTree T) {
    if(T == NULL) {
        return;
    }
    postOrderTraverse(T->lchild);
    postOrderTraverse(T->rchild);
    visit(T);
}

void freeBSTree(BSTree &T) {
    if(T == NULL) {
        return;
    }
    freeBSTree(T->lchild);
    freeBSTree(T->rchild);
    free(T);
    T = NULL;
}

/**
 * 例题15 辅助函数
 * @param T
 * @param data
 */
void insertBSTNode(BSTree &T, ElemType data) {
    if(T == NULL) {
        T = (BSTNode*) malloc(sizeof (BSTNode));
        T->data = data;
        T->lchild = NULL;
        T->rchild = NULL;
    }else if(T->data > data) {
        insertBSTNode(T->lchild, data);
    }else if(T->data < data) {
        insertBSTNode(T->rchild, data);
    }
}

/**
 * 例题15 设计算法构建一颗二叉排序树
 * @param T
 * @param array
 * @param length
 */
void createBSTree(BSTree &T, ElemType array[], int length) {
   for(int i = 0; i < length; i++) {
       insertBSTNode(T, array[i]);
   }
}


/**
 * 例题16: 查找二叉排序树中值为 x 的节点所在的层数
 * @param T
 * @param x
 * @return
 */
int findLevelOfX(BSTree T, ElemType x) {
    if(T == NULL) {
        return 0;
    }
    if(T->data > x) {
        int left = findLevelOfX(T->lchild, x);
        if(left) {
            return left + 1;
        }
    }else if(T->data < x){
        int right = findLevelOfX(T->rchild, x);
        if(right) {
            return right + 1;
        }
    }else {
        return 1;
    }
}




/**
 * 例题17: 删除二叉排序树T中关键字为x的节点
 * @param T
 * @param x
 */
void deleteNodeX(BSTree &T, ElemType x) {
    if(T == NULL) {
        return;
    }
    if(T->data == x) {
        if(T->lchild == NULL) {
            BSTNode *node = T;
            T = T->rchild;
            free(node);
        }else if(T->rchild == NULL) {
            BSTNode *node = T;
            T = T->lchild;
            free(node);
        }else {
            BSTNode *pre = T;
            BSTNode *node = T->lchild;
            while(node->rchild != NULL) {
                pre = node;
                node = node->rchild;
            }
            T->data = node->data;
            pre->lchild = node->lchild;
            free(node);
        }
    }else if(x < T->data) {
        deleteNodeX(T->lchild, x);
    }else {
        deleteNodeX(T->rchild, x);
    }
}

/**
 * 例题18: 查找二叉排序树中所有小于key的关键字
 * @param T
 * @param key
 */
void findNodeLessKey(BSTree T, ElemType key) {
    if(NULL == T){
        return;
    }
    findNodeLessKey(T->lchild, key);
    if(T->data < key) {
        printf("%d ", T->data);
    }else {
        return;
    }
    findNodeLessKey(T->rchild, key);
}


void mergeBSTree(BSTNode *node, BSTree &T) {
    if(T == NULL) {
        T = node;
    }else if(node->data < T->data) {
        mergeBSTree(node, T->lchild);
    }else {
        mergeBSTree(node, T->rchild);
    };
}

/**
 * 例题19: 编写算法,将一棵二叉排序树 T 分别成两颗二叉排序树t1和t2,t1的值都小于x,t2的值都大于x
 * @param T
 * @param T1
 * @param T2
 * @param x
 */
void departBSTree(BSTree &T, BSTree &T1, BSTree &T2, ElemType x) {
    if(T == NULL) {
        return;
    }
    if(x == T->data) {
        mergeBSTree(T->lchild, T1);
        mergeBSTree(T->rchild, T2);
        free(T);
        T = NULL;
    }else if(T->data > x){
        departBSTree(T->lchild, T1, T2, x);
        T->lchild = NULL;
        mergeBSTree(T, T2);
    }else if(T->data < x){
        departBSTree(T->rchild, T1, T2, x);
        T->rchild = NULL;
        mergeBSTree(T, T1);
    }
}



/**
 * 例题20: 编写算法删除二叉排序树中所有关键字小于x的结点
 * @param T
 * @param x
 */
void deleteNodeLessX(BSTree &T, ElemType x) {
    if(T == NULL) {
        return;
    }
    if(T->data == x) {
        freeBSTree(T->lchild);
    }else if(T->data > x) {
        deleteNodeLessX(T->lchild, x);
    }else if(T->data < x) {
        BSTNode *node = T;
        T = T->rchild;
        node->rchild = NULL;
        freeBSTree(node);
        deleteNodeLessX(T, x);
    }
}







/**
 * 已知二叉排序树中每一个结点值为整形，采用二又链表存储编写算法，删除二叉排序中所有节点值小于x的结点
 */
void deleteLessThanX(BSTree &T, int x) {
    if(T == NULL) return;
    if(T->data < x) {
        BSTNode *node = T;
        T = T->rchild;
        node->rchild = NULL;
        freeBSTree(node);
        deleteNodeLessX(T, x);
    }else if(T->data == x) {
        BSTNode *node = T->lchild;
        freeBSTree(node);
        T->lchild = NULL;
    }else if(T->data > x) {
        deleteNodeLessX(T->lchild, x);
    }
}










/**
* 假设二又树终止为x的结点不少于1个,采用二叉链表存储，编写算法，打印值为 X的结点的所有祖先。
*/


/**
 * 算法思想:使用后序遍历,若子树中存在x则打印当前节点
 */

int postOrder_X(BSTree T, ElemType x) {
    if(T == NULL) return 0;

    int ret = 0;
    if(postOrder_X(T->lchild, x)) {
        ret = 1;
    }
    if(postOrder_X(T->rchild,x)) {
        ret = 1;
    }
    if(ret) {
        printf("%d ", T->data);
    }
    return T->data == x || ret;
}






/**
* 已知二叉树采用二叉链表存储结构，设计算法求二叉树中指定结点所在的层数
*/

/**
* 算法思想:使用先序遍历,每次递归将层数+1,若当前节点为带查找节点x,则返回当前递归的level层数,
 * 若当前节点不是x,则递归查找并返回左右子树中最大的level
*/

int findLevel(BSTree T, ElemType x, int level) {
    if(T == NULL) return 0;
    if(T->data == x) {
        return level;
    }
    int level1 = findLevel(T->lchild, x, level + 1);
    int level2 = findLevel(T->rchild, x, level + 1);
    return level1 > level2 ? level1 : level2;
}












/**
 * 设计算法判断一棵二叉链表树是否为二叉排序树。
 * @param T
 * @return
 */
int isBSTree(BSTree T) {
    if(T == NULL) return 1;
    int ret = 1;
    if((T->lchild && T->data < T->lchild->data) || (T->rchild && T->data > T->rchild->data)) {
        ret = 0;
    }
    return ret && isBSTree(T->lchild) && isBSTree(T->rchild);
}




//打印距离最远的两个节点的路径
BSTNode *farRoot = NULL;
int maxDepth = 0;


//计算树的深度
int getDepth(BSTree T) {                //找到左右子树有最大距离的根节点
    if(T == NULL) {
        return 0;
    }
    if(T->lchild == NULL && T->rchild == NULL) {
        return 1;
    }
    int lDepth = getDepth(T->lchild);
    int rDepth = getDepth(T->rchild);
    int max = lDepth > rDepth ? lDepth : rDepth;
    if(max > maxDepth) {
        maxDepth = max;
        farRoot = T;
    }
    return max + 1;
}


BSTNode *lMaxNode = NULL;
BSTNode *rMaxNode = NULL;
void preOrder(BSTree T, int level, BSTNode *parent, BSTNode *&maxNode) {            //找到T下最大节点
    if(T == NULL) return;
    T->level = level;
    T->parent = parent;
    if(maxNode == NULL || maxNode->level < level) {
        maxNode = T;
    }
    preOrder(T->lchild, level + 1, T, maxNode);
    preOrder(T->rchild, level + 1, T, maxNode);
}


void findMaxPath(BSTree T) {
    getDepth(T);
    if(farRoot == NULL) return;
    preOrder(farRoot->lchild, 1, farRoot, lMaxNode);
    preOrder(farRoot->rchild, 1, farRoot, rMaxNode);
    while (lMaxNode != farRoot) {
        printf("%d ", lMaxNode->data);
        lMaxNode = lMaxNode->parent;
    }
    int path[100];
    int length = 0;
    while(rMaxNode != farRoot) {
        path[length++] = rMaxNode->data;
        rMaxNode = rMaxNode->parent;
    }
    path[length++] = farRoot->data;
    for (int i = length - 1; i >= 0; --i){
        printf("%d ", path[i]);
    }
    printf("\n");
}


































































