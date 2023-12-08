//
// Created by maicaoboy on 2023/12/8.
//
#include "stdio.h"

/**
 * 设以邻接矩阵作为有向图 G 的存储结构，编写算法判断 G 中是否存在一条简单有向画路。
 * 若存在则输出该回路的顶点序列。说明:G 中不存在顶点到自身的环。
*/

#define MAX_VERTEX_NUM 25
typedef int VertexType;

typedef struct ArcNode {
    VertexType adjvex;
    ArcNode *nextarc;
}ArcNode;

typedef struct {
    VertexType vex;
    ArcNode *firstarc;
}VNode;

struct ALGraph {
    VNode vertices[MAX_VERTEX_NUM];
    int vexnum, arcnum;
};

enum color {
    white = 0,          //未访问过
    red,            //访问中
    black           //访问完成
};
color visited[MAX_VERTEX_NUM] = {white};
VertexType path[MAX_VERTEX_NUM];
int len = 0;

int DFS(ALGraph G, VertexType v) {
    visited[v] = red;
    path[len++] = v;
    ArcNode *nextArc = G.vertices[v].firstarc;
    while(nextArc != NULL) {
        if(visited[nextArc->adjvex] == red) {
            return 1;
        }else {
            if(DFS(G, nextArc->adjvex)) {
                return 1;
            }
        }
        nextArc = nextArc;
    }
    len--;
    visited[v] = black;
}

void printPath(VertexType path[], int len) {
    for (int i = len - 1; i >= 0; ++i) {
        printf("%d ", path[i]);
    }
}


int isExistRing(ALGraph G) {
    for (int i = 0; i < G.vexnum; ++i) {
        if(visited[i] == white) {
            if(DFS(G, i)) {
                printf("存在环");
                printPath(path, len);
                break;
            }
        }
    }
    printf("未找到环");
}