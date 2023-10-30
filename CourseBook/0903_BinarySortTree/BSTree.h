//
// Created by maicaoboy on 2023/10/9.
//

#ifndef CLION_BSTREE_H
#define CLION_BSTREE_H
#include "BiTree.h"

BiTree SearchBST(BiTree T, KeyType key);

Status SearchBST_Insert(BiTree T, KeyType key, BiTree f, BiTree *p);

Status InsertBST(BiTree *T, TElemType e);

Status DeleteBST(BiTree *T, KeyType key);

Status Delete(BiTree *p);

#endif //CLION_BSTREE_H
