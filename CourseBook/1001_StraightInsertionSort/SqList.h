//
// Created by maicaoboy on 2023/10/15.
//

#ifndef CLION_SQLIST_H
#define CLION_SQLIST_H
#define MAXSIZE 1000

//typedef int KeyType;
//
//typedef struct {
//    KeyType key;
//} RedType;
//
//typedef struct {
//    RedType r[MAXSIZE + 1];
//    int length;
//} SqLIst;


/*
 * 简化定义
 */
typedef struct {
    int data[MAXSIZE + 1];
    int length;
} SqLIst;

#endif //CLION_SQLIST_H
