//
// Created by maicaoboy on 2023/12/17.
//
#include "stdio.h"
#include "stdlib.h"

#define MAX_VERTEX_NUM 20

typedef int VertexType;


typedef struct{
    VertexType vexs[MAX_VERTEX_NUM];
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexnum, arcnum;
}MGraph;


int visited[MAX_VERTEX_NUM] = {0};
int isIn[MAX_VERTEX_NUM];
int path[MAX_VERTEX_NUM];
int length = 0;


void process(MGraph G, VertexType path[MAX_VERTEX_NUM], VertexType isIn[MAX_VERTEX_NUM], int length) {
    for (int i = 0; i < G.vexnum; ++i) {
        int flag = 0;
        for (int j = 0; j < length; ++j) {
            if(isIn[i] == 1 && path[j] == i){
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            isIn[i] = 0;
        }
    }
}

void DFS(MGraph G, VertexType v, VertexType w) {
    visited[v] = 1;
    path[length++] = v;
    if(w == v) {
        process(G, path, isIn, length);
    }
    for (int i = 0; i < G.vexnum; ++i) {
        if(G.arcs[v][i] == 1 && visited[i] == 0) {
            DFS(G, i, w);
        }
    }
    visited[v] = 0;
    length--;
}

int main() {
    MGraph G;
    G.vexnum = 7;
    G.arcnum = 10;
    for (int i = 0; i < G.vexnum; ++i) {
        isIn[i] = 1;
    }
    for (int i = 0; i < MAX_VERTEX_NUM; ++i) {
        for (int j = 0; j < MAX_VERTEX_NUM; ++j) {
            G.arcs[i][j] = 0;
        }
    }
    G.arcs[0][1] = 1;
    G.arcs[0][2] = 1;
    G.arcs[0][3] = 1;

    G.arcs[1][3] = 1;
    G.arcs[2][3] = 1;
    G.arcs[3][4] = 1;
    G.arcs[3][5] = 1;
    G.arcs[3][6] = 1;


    G.arcs[4][6] = 1;
    G.arcs[5][6] = 1;

    VertexType v = 0, w = 6;
    DFS(G, v, w);
    isIn[v] = 0;
    isIn[w] = 0;

    for (int i = 0; i < G.vexnum; ++i){
        if(isIn[i] == 1) {
            printf("%d ", i);
        }
    }
}



