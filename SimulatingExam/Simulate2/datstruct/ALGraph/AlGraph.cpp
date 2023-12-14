//
// Created by maicaoboy on 2023/12/14.
//

#include "stdio.h"
#include "stdlib.h"

#define MAX_VERTEX_NUM 25
#define INF 9999

typedef int VertexType;

typedef struct ArcNode {
    VertexType adjvex;
    ArcNode *nextarc;
}ArcNode;

typedef struct {
    VertexType vex;
    ArcNode *firstarc;
}VNode;

typedef struct {
    VNode vertices[MAX_VERTEX_NUM];
    int vexnum,arcnum;
}ALGraph;

void printPath(VertexType path[MAX_VERTEX_NUM], int vexnum);

void dijkstra(ALGraph G, VertexType v) {
    VertexType path[MAX_VERTEX_NUM] = {-1};
    int length[MAX_VERTEX_NUM] = {INF};
    int isAdd[MAX_VERTEX_NUM] = {0};

    isAdd[v] = 1;
    ArcNode *nextArc = G.vertices[v].firstarc;
    path[v] = -1;
    while(nextArc != NULL) {
        path[nextArc->adjvex] = v;
        length[nextArc->adjvex] = 1;
        nextArc = nextArc->nextarc;
    }

    while(1) {
        int min = -1;
        for (int i = 1; i <= G.vexnum; ++i){
            if(length[i] < length[min] && !isAdd[i]) {
                min = i;
            }
        }
        if(min == -1) break;
        isAdd[min] = 1;
        nextArc = G.vertices[min].firstarc;
        while(nextArc != NULL) {
            if(length[nextArc->adjvex] > length[min] + 1) {
                length[nextArc->adjvex] = length[min] + 1;
                path[nextArc->adjvex] = min;
            }
            nextArc = nextArc->nextarc;
        }
    }

    printPath(path, G.vexnum);
}


void shortestPath() {
    //队列
}

int main() {

}
