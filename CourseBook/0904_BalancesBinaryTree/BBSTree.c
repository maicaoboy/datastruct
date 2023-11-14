//
// Created by maicaoboy on 2023/10/12.
//


#include "BBSTree.h"
#include "stdlib.h"

/*
 * 算法9.9: 右旋操作
 */
void R_Rotate(BSTree *p) {
    BSTree lc;

    lc = (*p)->lchild;
    (*p)->lchild = lc->rchild;
    lc->rchild = (*p);
    *p = lc;
}


/*
 * 算法9.10: 左旋操作
 */
void L_Rotate(BSTree *p) {
    BSTree rc;

    rc = (*p)->rchild;
    (*p)->rchild = rc->lchild;
    rc->lchild = (*p);
    (*p) = rc;
}

Status InsertAvl(BSTree *T, ElemType e, Boolean *taller) {
    if(!(*T)) {
        *T = malloc(sizeof (BSTNode));
        (*T)->data = e;
        (*T)->lchild = (*T)->rchild = NULL;
    }else {
        if(EQ(e.key, (*T)->data.key)) {
            *taller = FALSE;
            return FALSE;
        }
        if(LT(e.key, (*T)->data.key)) {
            if(!InsertAvl(&(*T)->lchild, e, taller)) {
                return FALSE;   //  节点已存在,插入失败
            }
            if(*taller) {
                switch ((*T)->bf) {
                    case LH:
                        LeftBalance(T);
                        (*taller) = FALSE;
                        break;
                    case EH:
                        (*T)->bf = LH;
                        (*taller) = TRUE;
                        break;
                    case RH:
                        (*T)->bf = EH;
                        (*taller) = FALSE;
                        break;
                }
            }else {
                if(!InsertAvl(&(*T)->rchild,e, taller)) {
                    return FALSE;
                }
                if(*taller) {
                    switch ((*T)->bf) {
                        case LH:
                            (*T)->bf = EH;
                            (*taller) = FALSE;
                            break;
                        case EH:
                            (*T)->bf = RH;
                            (*taller) = TRUE;
                            break;
                        case RH:
                            RightBalance(T);
                            (*taller) = FALSE;
                            break;
                    }
                }
            }
        }
    }
    return TRUE;
}

void LeftBalance(BSTree *T) {
    BSTree lc, rd;

    lc = (*T)->lchild;

    switch (lc->bf) {
        case LH:
            (*T)->bf = lc->bf = EH;
            R_Rotate(T);
            break;
        case RH:
            rd = lc->rchild;
            switch (rd->bf) {
                case LH:
                    (*T)->bf = RH;
                    lc->bf = EH;
                    break;
                case EH:
                    (*T)->bf = lc->bf = EH;
                    break;
                case RH:
                    (*T)->bf = EH;
                    lc->bf = LH;
                    break;
            }
            rd->bf = EH;
            L_Rotate(&(*T)->lchild);
            R_Rotate(T);
    }
}

void RightBalance(BSTree *T);












