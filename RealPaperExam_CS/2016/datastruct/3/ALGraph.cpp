//
// Created by maicaoboy on 2023/12/9.
//
#include "stdio.h"
#include "stdlib.h"

#define MAX_VERTEX_NUM 25
typedef int VertexType;


typedef struct ArcNode {
    VertexType adjvex;
    struct ArcNode *nextarc;
}ArcNode;

typedef struct {
    VertexType vex;
    ArcNode *firstarc;
}VNode;


struct ALGraph {
    VNode vertices[MAX_VERTEX_NUM];
    int vexnum, arcnum;
};


/**
* 设计算法，求邻接表存储结构的无向图的连通分量的个数，并输出每个连通分量的顶点集
*/

/**
 * 算法思想:从第一个顶点使用DFS访问每个顶点,在每次访问完成后对比访问前后变化了的节点即为一个连通分量
 * */

int visited[MAX_VERTEX_NUM] = {0};

void DFS(ALGraph G, VertexType v) {
    visited[v] = 1;
    ArcNode *nextArc = G.vertices[v].firstarc;
    while(nextArc != NULL) {
        if(!visited[nextArc->adjvex]) {
            DFS(G, nextArc->adjvex);
        }
        nextArc = nextArc->nextarc;
    }
}

void copyVisited(int previsited[MAX_VERTEX_NUM], int visited[MAX_VERTEX_NUM]) {
    for (int i = 0; i < MAX_VERTEX_NUM; ++i){
        previsited[i] = visited[i];
    }
}

void printfLianTong(ALGraph G, int visited[MAX_VERTEX_NUM], int previsited[MAX_VERTEX_NUM]) {
    printf("连通分量顶点: ");
    for (int i = 0; i < G.vexnum; ++i) {
        if(previsited[i] == 0 && visited[i] == 1) {
            printf("%d ", G.vertices[i].vex);
        }
    }
    printf("\n");
}


void findLianTong(ALGraph G) {
    int previsited[MAX_VERTEX_NUM] = {0};
    int cnt = 0;
    for (int i = 0; i < G.vexnum; ++i){
        if(!visited[i]) {
            copyVisited(previsited, visited);//保存visited数组
            DFS(G, i);    //从i顶点出发深度偶先访问
            printfLianTong(G, visited, previsited);   //打印一次连通分量顶点集
            cnt++;
        }
    }
    printf("总连通分量个数:%d", cnt);
}
