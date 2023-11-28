//
// Created by maicaoboy on 2023/11/28.
//
#include "stdio.h"
#include "stdlib.h"

#define MAX_VERTEX_NUM 20

// 顶点类型
typedef int VertexType;


/* 边/弧结点 */
typedef struct ArcNode {
    int adjvex;                 // 该弧所指向的顶点的位置
    struct ArcNode* nextarc;    // 指向下一条弧的指针
} ArcNode;

// 每个链表的头结点
typedef struct VNode {
    VertexType data;    // 顶点信息
    ArcNode* firstarc;  // 指向第一条依附该顶点的弧的指针
} VNode;

/* 图的邻接表存储表示类型定义 */
typedef struct {
    VNode vertices[MAX_VERTEX_NUM]; // 邻接表
    int vexnum, arcnum;             // 图/网的顶点数和弧数
} ALGraph;


//初始化图
void initGraph(ALGraph &G, int vexnum){
    G.vexnum = vexnum;
    G.arcnum = 0;

    for (int i = 1; i <= vexnum; ++i) {
        G.vertices[i].data = i;
        G.vertices[i].firstarc = NULL;
    }
}



//打印图
void printGraph(ALGraph G){
    for (int i = 1; i <= G.vexnum; ++i) {
        printf("%d:", G.vertices[i].data);
        ArcNode *ptr = G.vertices[i].firstarc;
        while(ptr != NULL){
            printf("->%d", ptr->adjvex);
            ptr = ptr->nextarc;
        }
        printf("\n");
    }
}



//遍历图G邻接表的每一个点,对每一个点遍历邻接边然后插入到逆邻接表中
void convert(VNode *nodes, int vexnum, VNode *nodes_rv) {
    for (int i = 1; i <= vexnum; ++i) {
        nodes_rv[i].data = i;
        nodes_rv[i].firstarc = NULL;
    }
    for (int i = 1; i <= vexnum; ++i) {
        VNode node = nodes[i];
        ArcNode *arc = nodes[i].firstarc;
        while(arc != NULL) {
            ArcNode *newNode = (ArcNode*) malloc(sizeof (ArcNode));
            newNode->adjvex = node.data;
            newNode->nextarc = nodes_rv[arc->adjvex].firstarc;
            nodes_rv[arc->adjvex].firstarc = newNode;
            arc = arc->nextarc;
        }
    }
}



int main() {
    //初始化图
    ALGraph G;
    initGraph(G, 8);
    //插入节点
    ArcNode *arc = (ArcNode*) malloc(sizeof (ArcNode));
    arc->adjvex = 2;
    arc->nextarc = G.vertices[1].firstarc;
    G.vertices[1].firstarc = arc;

    arc = (ArcNode*) malloc(sizeof (ArcNode));
    arc->adjvex = 4;
    arc->nextarc = G.vertices[1].firstarc;
    G.vertices[1].firstarc = arc;

    arc = (ArcNode*) malloc(sizeof (ArcNode));
    arc->adjvex = 5;
    arc->nextarc = G.vertices[1].firstarc;
    G.vertices[1].firstarc = arc;

    arc = (ArcNode*) malloc(sizeof (ArcNode));
    arc->adjvex = 7;
    arc->nextarc = G.vertices[2].firstarc;
    G.vertices[2].firstarc = arc;


    arc = (ArcNode*) malloc(sizeof (ArcNode));
    arc->adjvex = 8;
    arc->nextarc = G.vertices[2].firstarc;
    G.vertices[2].firstarc = arc;


    arc = (ArcNode*) malloc(sizeof (ArcNode));
    arc->adjvex = 2;
    arc->nextarc = G.vertices[3].firstarc;
    G.vertices[3].firstarc = arc;

    arc = (ArcNode*) malloc(sizeof (ArcNode));
    arc->adjvex = 7;
    arc->nextarc = G.vertices[3].firstarc;
    G.vertices[3].firstarc = arc;

    arc = (ArcNode*) malloc(sizeof (ArcNode));
    arc->adjvex = 8;
    arc->nextarc = G.vertices[3].firstarc;
    G.vertices[3].firstarc = arc;

    arc = (ArcNode*) malloc(sizeof (ArcNode));
    arc->adjvex = 1;
    arc->nextarc = G.vertices[4].firstarc;
    G.vertices[4].firstarc = arc;

    arc = (ArcNode*) malloc(sizeof (ArcNode));
    arc->adjvex = 2;
    arc->nextarc = G.vertices[4].firstarc;
    G.vertices[4].firstarc = arc;

    arc = (ArcNode*) malloc(sizeof (ArcNode));
    arc->adjvex = 3;
    arc->nextarc = G.vertices[5].firstarc;
    G.vertices[5].firstarc = arc;

    arc = (ArcNode*) malloc(sizeof (ArcNode));
    arc->adjvex = 4;
    arc->nextarc = G.vertices[6].firstarc;
    G.vertices[6].firstarc = arc;

    arc = (ArcNode*) malloc(sizeof (ArcNode));
    arc->adjvex = 5;
    arc->nextarc = G.vertices[6].firstarc;
    G.vertices[6].firstarc = arc;

    arc = (ArcNode*) malloc(sizeof (ArcNode));
    arc->adjvex = 8;
    arc->nextarc = G.vertices[6].firstarc;
    G.vertices[6].firstarc = arc;

    printGraph(G);

    ALGraph G1;
    initGraph(G1, 8);

    convert(G.vertices, G.vexnum, G1.vertices);

    printGraph(G1);

}

