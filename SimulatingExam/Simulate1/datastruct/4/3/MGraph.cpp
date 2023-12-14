//
// Created by maicaoboy on 2023/12/12.
//
#include "stdio.h"
#include "stdlib.h"

#define MAX_VERTEX_NUM 25

typedef int VertexType;

struct MGraph{
    VertexType vertex[MAX_VERTEX_NUM + 1];
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int arcnum, vexnum;
};

void printPath(VertexType path[MAX_VERTEX_NUM], VertexType  v, int length);

int visited[MAX_VERTEX_NUM] = {0};
VertexType path[MAX_VERTEX_NUM] = {-1};
int length = 0;

void DFS(MGraph G, VertexType v, int k) {
    if(k == 0) {
        printPath(path, v, length);
        return;
    }
    visited[v] = 1;
    path[length++] = v;


    for (int i = 0; i < G.vexnum; ++i) {
        if(G.arcs[v][i] == 1 && visited[i] != 1) {
            DFS(G, i, k - 1);
        }
    }

    visited[v] = 0;
    length--;
}


void printPath(VertexType path[MAX_VERTEX_NUM], VertexType  v, int length) {
    printf("path(%d->%d):", path[0], path[length - 1]);
    for (int i = 0; i < length; ++i) {
        printf("%d ", path[i]);
    }
    printf("\n");
}


int main() {
    MGraph G;
    G.vexnum = 8;
    G.arcnum = 10;
    for (int i = 0; i < G.vexnum; ++i) {
        G.vertex[i] = i;
    }
    for (int i = 0; i < G.vexnum; ++i){
        for (int j = 0; j < G.vexnum; ++j) {
            G.arcs[i][j] = 0;
        }
    }
    G.arcs[0][7] = 1;
    G.arcs[1][0] = 1;
    G.arcs[2][3] = 1;
    G.arcs[3][4] = 1;
    G.arcs[3][5] = 1;
    G.arcs[6][5] = 1;
    G.arcs[7][6] = 1;
    G.arcs[8][7] = 1;
    G.arcs[8][1] = 1;
    G.arcs[8][2] = 1;
    G.arcs[8][4] = 1;

    int k = 2;
    DFS(G, 8, k + 1);
    return 0;
}