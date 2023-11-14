//
// Created by maicaoboy on 2023/10/12.
//

#ifndef CLION_BBSTREE_H
#define CLION_BBSTREE_H

#include "BBSTNode.h"
#include "Status.h"

void R_Rotate(BSTree *p);

void L_Rotate(BSTree *p);

Status InsertAvl(BSTree *T, ElemType e, Boolean *Taller);

void LeftBalance(BSTree *T);

void RightBalance(BSTree *T);

#endif //CLION_BBSTREE_H
