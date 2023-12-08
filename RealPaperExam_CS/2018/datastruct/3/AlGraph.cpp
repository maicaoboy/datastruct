//
// Created by maicaoboy on 2023/12/7.
//

#include "stdio.h"
#include "stdlib.h"
#define VertexType int
#define MAX_VERTEX_SIZE 25

typedef struct ArcNode{
    VertexType adjvex;
    struct ArcNode *nextarc;
}ArcNode;

typedef struct {
    VertexType vex;
    ArcNode *firstarc;
}VNode;

struct AlGraph {
    VNode vertices[MAX_VERTEX_SIZE];
    int vexnum, arcnum;
};


typedef struct {
    VertexType v;
    int index;
    int level;
}QElemType;

int isExistPathK_BFS(AlGraph G, VertexType v, VertexType w, int k) {
    int visited[MAX_VERTEX_SIZE] = {0};
    QElemType queue[MAX_VERTEX_SIZE];
    int qLength = 0;
    int index = 0;

    queue[qLength].v = v;
    queue[qLength].index = -1;
    queue[qLength].level = 1;
    visited[v] = 1;
    qLength++;

    while(index < qLength) {
        QElemType node = queue[index];
        ArcNode *nextArc = G.vertices[node.v].firstarc;
        while(nextArc != NULL) {
            if(!visited[nextArc->adjvex]) {
                queue[qLength].v = nextArc->adjvex;
                queue[qLength].index = index;
                queue[qLength].level = queue[index].level + 1;
                visited[nextArc->adjvex] = 1;
                if(nextArc->adjvex == w) {
                    if(queue[qLength].level == k + 1) {
                        return true;
                    }else {
                        return false;
                    }
                }
                qLength++;
            }
            nextArc = nextArc->nextarc;
        }
    }
    return false;
}


































