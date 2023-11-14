//
// Created by maicaoboy on 2023/10/8.
//
#include "BiTree.h"
#include "BSTree.h"

#define EQ(a, b) ((a) == (b))
#define LT(a, b) ((a) < (b))
#define LQ(a, b) ((a) <= (b))

/**
 * 算法9.4
 * @param T 根节点
 * @param key  查找的值
 * @return 查找到的节点
 */
BiTree SearchBST(BiTree T, KeyType key) {
    if((!T) || EQ(key, T->data.key)) {
        return T;
    }else if(LT(key, T->data.key)) {
        return SearchBST(T->lchild, key);
    }else {
        return SearchBST(T->rchild, key);
    }
}

/**
 * 算法9.5 用于插入前查找
 * @param T
 * @param key
 * @param f
 * @param p
 * @return
 */

Status SearchBST_Insert(BiTree T, KeyType key, BiTree f, BiTree *p) {
    if(!T) {
        *p = f;
        return FALSE;
    }else if(EQ(key, T->data.key)) {
        *p = T;
        return TRUE;
    }else if(LT(key, T->data.key)) {
        return SearchBST_Insert(T->lchild, key, T , p);
    }else {
        return SearchBST_Insert(T->rchild, key, T, p);
    }
}


/**
 * 算法9.6,插入元素e
 * @param T
 * @param e
 * @return
 */
Status InsertBST(BiTree *T, TElemType e) {
    BiTree p = NULL, s = NULL;

    if(!SearchBST_Insert(*T, e.key, NULL, &p)) {
        s = (BiTree) malloc(sizeof(BiTNode));
        s->lchild = s->rchild = NULL;
        s->data = e;

        if(!p) {
            (*T) = s;
        }else if(LT(e.key, p->data.key)){
            p->lchild = s;
        }else {
            p->rchild = s;
        }
        return TRUE;
    }else {
        return FALSE;
    }
}

/**
 * 算法9.7, 删除key
 * @param T
 * @param key
 * @return
 */
Status DeleteBST(BiTree *T, KeyType key) {
    if(!T) {
        return FALSE;
    }else {
        if(EQ(key, (*T)->data.key)) {
            return Delete(T);
        }else if(LT(key, (*T)->data.key)) {
            return DeleteBST(&(*T)->lchild, key);
        }else {
            return DeleteBST(&(*T)->rchild, key);
        }
    }
}

/**
 * 算法9.8,删除含key的p节点
 * @param p
 * @return
 */
Status Delete(BiTree *p) {
    BiTree q, s, ptr;

    ptr = (*p);

    if(!ptr->rchild) {
        q = ptr;
        (*p) = ptr->lchild;
        free(q);
    }else if(!ptr->lchild) {
        q = ptr;
        (*p) = ptr->rchild;
        free(q);
    }else {
        q = ptr;
        s = ptr->lchild;
        while(s->rchild) {
            q = s;
            s = s->rchild;
        }

        ptr->data = s->data;
        if(q != ptr) {
            q->rchild = s->lchild;
        }else {
            q->lchild = s->lchild;
        }
        free(s);
    }
    return TRUE;
}

