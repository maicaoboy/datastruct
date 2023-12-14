//
// Created by maicaoboy on 2023/12/10.
//
#include "stdio.h"
#include "stdlib.h"

#define MAX_VERTEX_NUM 25
typedef int VertexType;

typedef struct ArcNode{
    VertexType adjvex;
    struct ArcNode *nextarc;
} ArcNode;

typedef struct {
    VertexType vex;
    ArcNode *firstarc;
}VNode;


typedef struct {
    VNode vertices[MAX_VERTEX_NUM];
    int vexnum, arcnum;
}ALGraph;

typedef struct {
    VertexType v;
    int level;
}QElemType;

void BFS_2015(ALGraph G, VertexType v, VertexType v0, int k){
    QElemType queue[MAX_VERTEX_NUM];
    int visited[MAX_VERTEX_NUM] = {0};
    int length = 1;
    int index = 1;
    visited[v] = 1;

    queue[length].v = v;
    queue[length].level = 1;
    length++;

    while(index < length) {
        ArcNode *nextArc = G.vertices[queue[index].v].firstarc;
        while(nextArc != NULL) {
            if(!visited[nextArc->adjvex]) {
                if(nextArc->adjvex == v0) {
                    if(queue[index].level == k) {
                        printf("%d ", nextArc->adjvex);
                    }
                    return;
                }
                visited[nextArc->adjvex] = 1;
                queue[length].v = nextArc->adjvex;
                queue[length].level = queue[index].level + 1;
                visited[nextArc->adjvex] = 1;
                length++;
            }
            nextArc = nextArc->nextarc;
        }
        index++;
    }
}



/**
 * 求出无向联通图距离顶点v0的最短路径长度为K的所有节点
 * 算法思想:对图的每个顶点使用广度优先遍历,若找到的最短路径为K则输出该节点
 * @param G
 * @param v         起始顶点
 * @param v0        终点
 * @param k
 */
void findShortestPathK(ALGraph G, VertexType v0, int k) {
    for (int i = 1; i <= G.vexnum; ++i) {
        if(i != v0) {
            BFS_2015(G, i, v0, k);
        }
    }
}


