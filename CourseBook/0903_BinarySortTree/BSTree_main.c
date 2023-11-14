//
// Created by maicaoboy on 2023/10/9.
//

#include "BSTree.h"
#include "BSTree.h"

void middleTravers(BiTree T) {
    if(!T) {
        return;
    }

    middleTravers(T->lchild);

    printf("%d ", T->data.key);

    middleTravers(T->rchild);

};

int main(int argc, char** argv) {
    BiTNode node;
    int i;
    BiTree T, F;
    int find;

    T = &node;
    node.lchild = NULL;
    node.rchild = NULL;
    node.data.key = 10;

    int nodes[] = {4,3,1,7,8,2,19,13,56,44,24};

    for(i = 0; i < sizeof(nodes)/sizeof(int); i++) {
        TElemType *data = malloc(sizeof(TElemType));
        data->key = nodes[i];
        InsertBST(&T, *data);
    }

    printf("插入序列为:");
    for(i = 0; i < sizeof(nodes)/sizeof(int); i++) {
        printf("%d ", nodes[i]);
    }
    printf("\n");

    printf("输入后中序遍历为:");
    middleTravers(T);
    printf("\n");

    find = 19;
    printf("查找%d:", find);
    F = SearchBST(T, find);
    if(F) {
        printf("查找到节点key:%d, 左子树key:%d, 右子树key:%d",
               F->data.key,
               F->lchild ? F->lchild->data.key : -999,
               F->rchild ? F->rchild->data.key : -999);
    }else {
        printf("未找到节点");
    }
}