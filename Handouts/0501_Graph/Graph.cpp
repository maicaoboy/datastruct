//
// Created by maicaoboy on 2023/11/18.
//
#include "stdio.h"
#include "stdlib.h"

/* 宏定义 */
#define MAX_VERTEX_NUM 26   // 最大顶点个数
#define INF 999999

#define TRUE 1
#define FALSE 0

int visited[MAX_VERTEX_NUM] = {0};

// 图的类型
typedef enum {
    DG,     // 0-有向图
    DN,     // 1-有向网(带权值)
    UDG,    // 2-无向图
    UDN     // 3-无向网(带权值)
} GraphKind;

// 顶点类型
typedef int VertexType;

/* 边/弧结点 */
typedef struct ArcNode {
    int adjvex;                 // 该弧所指向的顶点的位置
    struct ArcNode* nextarc;    // 指向下一条弧的指针
    int weight;
} ArcNode;

// 每个链表的头结点
typedef struct VNode {
    VertexType vex;    // 顶点信息
    ArcNode* firstarc;  // 指向第一条依附该顶点的弧的指针
} VNode;

/* 图的邻接表存储表示类型定义 */
typedef struct {
    VNode vertices[MAX_VERTEX_NUM]; // 邻接表
    int vexnum, arcnum;             // 图/网的顶点数和弧数
    GraphKind kind;                 // 图的类型标志
} ALGraph;




// 顶点类型
typedef int VertexType;

typedef int VRType;

typedef struct ArcCell {
    VRType adj;  // 顶点关系，在有权图跟无权图中的含义不同
} ArcCell;

/* 图/网的数组(邻接矩阵)存储表示类型定义 */
typedef struct {
    VertexType vexs[MAX_VERTEX_NUM];               // 顶点向量
    ArcCell arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  // 邻接矩阵
    int vexnum, arcnum;                            // 图/网的顶点数和弧数
    GraphKind kind;                                // 图的类型标志
} MGraph;



/**
 * 例题1:使用邻接表存储方式建立无向图G
 * !!!vex的值即为vex的索引
 * @param G
 * @param vex
 * @param vexnum
 * @param arc
 * @param arcnum
 */
void createALGraph_UDG(ALGraph &G, VertexType vex[], int vexnum, VertexType arc[][3], int arcnum) {
    G.vexnum = vexnum;
    G.arcnum = arcnum;
    G.kind = UDG;

    for(int i = 0; i < G.vexnum; i++) {
        VertexType vertex = vex[i];
        G.vertices[vertex].vex = vertex;
        G.vertices[vertex].firstarc = NULL;
    }

    for(int i = 0; i < arcnum; i++) {
        VertexType v = arc[i][0];
        VertexType w = arc[i][1];

        //v->w
        ArcNode *arcNode = (ArcNode*) malloc(sizeof(ArcNode));
        arcNode->adjvex = w;
        arcNode->nextarc = G.vertices[v].firstarc;
        G.vertices[v].firstarc = arcNode;

        //w->v
        ArcNode *arcNode1 = (ArcNode*) malloc(sizeof(ArcNode));
        arcNode1->adjvex = v;
        arcNode1->nextarc = G.vertices[w].firstarc;
        G.vertices[w].firstarc = arcNode1;
    }
}


/**
 * 例题1.1
 * 使用邻接表存储方式建立有向图G
 * !!!vex的值即为vex的索引
 * @param G
 * @param vex
 * @param vexnum
 * @param arc
 * @param arcnum
 */
void createALGraph_DG(ALGraph &G, VertexType vex[], int vexnum, VertexType arc[][3], int arcnum) {
    G.vexnum = vexnum;
    G.arcnum = arcnum;
    G.kind = DG;

    for(int i = 0; i < G.vexnum; i++) {
        VertexType vertex = vex[i];
        G.vertices[vertex].vex = vertex;
        G.vertices[vertex].firstarc = NULL;
    }

    for(int i = 0; i < arcnum; i++) {
        VertexType v = arc[i][0];
        VertexType w = arc[i][1];

        //v->w
        ArcNode *arcNode = (ArcNode*) malloc(sizeof(ArcNode));
        arcNode->adjvex = w;
        arcNode->nextarc = G.vertices[v].firstarc;
        G.vertices[v].firstarc = arcNode;
    }

}

/**
 * 例题1.2:使用邻接表存储方式建立无向网G
 * !!!vex的值即为vex的索引
 * @param G
 * @param vex
 * @param vexnum
 * @param arc
 * @param arcnum
 */
void createALGraph_UDN(ALGraph &G, VertexType vex[], int vexnum, VertexType arc[][3], int arcnum) {
    G.vexnum = vexnum;
    G.arcnum = arcnum;
    G.kind = UDN;

    for(int i = 0; i < G.vexnum; i++) {
        VertexType vertex = vex[i];
        G.vertices[vertex].vex = vertex;
        G.vertices[vertex].firstarc = NULL;
    }

    for(int i = 0; i < arcnum; i++) {
        VertexType v = arc[i][0];
        VertexType w = arc[i][1];

        //v->w
        ArcNode *arcNode = (ArcNode*) malloc(sizeof(ArcNode));
        arcNode->adjvex = w;
        arcNode->weight = arc[i][2];
        arcNode->nextarc = G.vertices[v].firstarc;
        G.vertices[v].firstarc = arcNode;

        //w->v
        ArcNode *arcNode1 = (ArcNode*) malloc(sizeof(ArcNode));
        arcNode1->adjvex = v;
        arcNode1->weight = arc[i][2];
        arcNode1->nextarc = G.vertices[w].firstarc;
        G.vertices[w].firstarc = arcNode1;
    }
}

/**
 * 例题1.3:使用邻接表存储方式建立无向网G
 * !!!vex的值即为vex的索引
 * @param G
 * @param vex
 * @param vexnum
 * @param arc
 * @param arcnum
 */
void createALGraph_DN(ALGraph &G, VertexType vex[], int vexnum, VertexType arc[][3], int arcnum) {
    G.vexnum = vexnum;
    G.arcnum = arcnum;
    G.kind = UDN;

    for(int i = 0; i < G.vexnum; i++) {
        VertexType vertex = vex[i];
        G.vertices[vertex].vex = vertex;
        G.vertices[vertex].firstarc = NULL;
    }

    for(int i = 0; i < arcnum; i++) {
        VertexType v = arc[i][0];
        VertexType w = arc[i][1];

        //v->w
        ArcNode *arcNode = (ArcNode*) malloc(sizeof(ArcNode));
        arcNode->adjvex = w;
        arcNode->weight = arc[i][2];
        arcNode->nextarc = G.vertices[v].firstarc;
        G.vertices[v].firstarc = arcNode;
    }
}

/**
 * 将边v->w插入有向图G
 * @param G
 * @param v
 * @param w
 */
void insertArc(ALGraph &G, VertexType v, VertexType w) {
    ArcNode *arcNode = (ArcNode*) malloc(sizeof (ArcNode));
    arcNode->nextarc = G.vertices[v].firstarc;
    arcNode->adjvex = w;
    G.vertices[v].firstarc = arcNode;
}

/**
 * 例题2: 将邻接表存储的有向图G转换成逆邻接表存储
 * @param G
 * @param rG
 */
void reverseALGraph(ALGraph G, ALGraph &rG) {
    rG.vexnum = G.vexnum;
    rG.arcnum = G.arcnum;
    for (int i = 1; i < G.vexnum; ++i) {
        rG.vertices[i].firstarc = NULL;
        rG.vertices[i].vex = G.vertices[i].vex;
    }


    for (int i = 1; i <= G.vexnum; ++i) {
        VNode vNode = G.vertices[i];
        VertexType v = vNode.vex;
        ArcNode *arcNext = vNode.firstarc;
        while(arcNext != NULL) {
            VertexType w = arcNext->adjvex;
            insertArc(rG, w, v);
            arcNext = arcNext->nextarc;
        }
    }
}



/**
 * 例题3: 设计算法计算有向图G中所有顶点的度
 * @param G
 * @param degree
 */
void degreeAlGraph_DG(ALGraph G, int degree[]) {
    for (int i = 1; i <= G.vexnum; ++i) {
        degree[i] = 0;
    }

    for (int i = 1; i <= G.vexnum; ++i) {
        VNode node = G.vertices[i];
        VertexType v = node.vex;
        ArcNode *nextArc = node.firstarc;
        while(nextArc != NULL) {
            VertexType w = nextArc->adjvex;
            degree[v]++;
            degree[w]++;
            nextArc = nextArc->nextarc;
        }
    }
}


/**
 * 算法4辅助函数,删除一条边 v -> w
 * @param G
 * @param v
 * @param w
 */
void deleteALGraphArc(ALGraph &G, VertexType v, VertexType w) {
    //删除 v->w
    VNode vNode = G.vertices[v];
    VertexType a = vNode.vex;
    ArcNode *nextArc = vNode.firstarc;
    if(nextArc->adjvex == w) {
        ArcNode *node = nextArc;
        G.vertices[v].firstarc = nextArc->nextarc;
        free(node);
    }else {
        while(nextArc->nextarc != NULL) {
            ArcNode *pre = nextArc;
            nextArc = nextArc->nextarc;
            if(nextArc->adjvex == w) {
                pre->nextarc = nextArc->nextarc;
                free(nextArc);
                break;
            }
        }
    }
}

/**
 * 算法4: 设计算法将邻接表方式存储的无向图G删除顶点v到顶点w的边。
 * @param G
 * @param v
 * @param w
 */
void deleteArc_UDG(ALGraph &G, int v, int w) {
    deleteALGraphArc(G, v, w);
    deleteALGraphArc(G, w, v);
}


//例题5: 将邻接表表示的有向网转换成邻接数组表示。
void converseARCNetToMNet(ALGraph G, MGraph &mG) {
    mG.kind = DN;
    mG.arcnum = G.arcnum;
    mG.vexnum = G.vexnum;
    for (int i = 1; i <= G.vexnum; ++i) {
        mG.vexs[i] = G.vertices[i].vex;
    }
    for (int i = 1; i <= mG.vexnum; ++i) {
        for (int j = 1; j <= mG.vexnum; ++j) {
            mG.arcs[i][j].adj = INF;
        }
    }

    for (int i = 1; i <= G.vexnum; ++i) {
        VNode vNode = G.vertices[i];
        VertexType v = vNode.vex;
        ArcNode *nextArc = vNode.firstarc;
        while(nextArc != NULL) {
            VertexType w = nextArc->adjvex;
            mG.arcs[v][w].adj = nextArc->weight;
            nextArc = nextArc->nextarc;
        }
    }

}



void visit(VertexType v) {
    printf("%d ", v);
}



//例题6: 对有向图G进行DFS遍历。
void DFS(ALGraph G, VertexType v) {
    visit(v);
    visited[v] = TRUE;
    VNode vNode = G.vertices[v];
    ArcNode *arcNode = vNode.firstarc;
    while(arcNode != NULL) {
        DFS(G, arcNode->adjvex);
        arcNode = arcNode->nextarc;
    }
}

void DFS(ALGraph G) {
    for (int i = 1; i <= G.vexnum; ++i) {
        visited[i] = FALSE;
    }
    for (int i = 1; i <= G.vexnum; ++i) {
        if(!visited[i]) {
            DFS(G, G.vertices[i].vex);
        }
    }
}






























void printGragh(ALGraph G) {
    printf("输出图结构:\n");
    printf("vexnum: %d, arcnum: %d\n", G.vexnum, G.arcnum);
    printf("vex:");
    for(int i = 1; i <= G.vexnum; i++) {
        printf("%d ", G.vertices[i].vex);
    }
    printf("\n");
    for (int i = 1; i <= G.vexnum; i++) {
        VNode node = G.vertices[i];
        ArcNode *arc = G.vertices[i].firstarc;
        while(arc != NULL) {
            printf("%d -> %d", node.vex, arc->adjvex);
            if(G.kind == DN || G.kind == UDN) {
                printf("  weight: %d", arc->weight);
            }
            printf("\n");
            arc = arc->nextarc;
        }
    }
}

void printGragh_mG(MGraph G) {
    printf("输出图结构:\n");
    printf("vexnum: %d, arcnum: %d\n", G.vexnum, G.arcnum);
    printf("vex:");
    for(int i = 0; i < G.vexnum; i++) {
        printf("%d ", G.vexs[i]);
    }
    printf("\n");
    printf("arc: \n");
    for (int i = 1; i <= G.vexnum; ++i) {
        for (int j = 1; j <= G.vexnum; ++j) {
            if(G.arcs[i][j].adj == INF){
                printf("-1\t");
            }else {
                printf("%d\t", G.arcs[i][j]);
            }
        }
        printf("\n");
    }
}

void freeGraph_ALGraph(ALGraph &G) {
    G.vexnum = 0;
    G.arcnum = 0;
    for(int i = 1; i <= G.vexnum; i++) {
        ArcNode *arcNext = G.vertices[i].firstarc;
        while(arcNext != NULL) {
            ArcNode *p = arcNext;
            arcNext = arcNext->nextarc;
            free(p);
        }
    }
}
















































