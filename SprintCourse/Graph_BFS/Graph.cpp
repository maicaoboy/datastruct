//
// Created by maicaoboy on 2023/11/18.
//从730行考开始
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
        VertexType v = G.vertices[i].vex;
        ArcNode *nextArc = G.vertices[i].firstarc;
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
    ArcNode *arcNode = G.vertices[v].firstarc;
    while(arcNode != NULL) {
        if(!visited[arcNode->adjvex]) {
            DFS(G, arcNode->adjvex);
        }
        arcNode = arcNode->nextarc;
    }
}

void DFSTraverse(ALGraph G) {
    for (int i = 1; i <= G.vexnum; ++i) {
        visited[i] = FALSE;
    }
    for (int i = 1; i <= G.vexnum; ++i) {
        if(!visited[i]) {
            DFS(G, G.vertices[i].vex);
        }
    }
}

#define white 0
#define red 1
#define black 2

int DFS_existRing(ALGraph G, VertexType v) {
    visited[v] = red;
    ArcNode *nextArc = G.vertices[v].firstarc;
    while(nextArc != NULL) {
        if(visited[nextArc->adjvex] == red) {
            return TRUE;
        }
        if(visited[nextArc->adjvex] == white) {
            int ret = DFS_existRing(G, nextArc->adjvex);
            if(ret == 1) {
                return TRUE;
            }
        }
        nextArc = nextArc->nextarc;
    }
    visited[v] = black;
    return FALSE;
}


/**
 * 例题 7、判断以邻接表为存储结构的有向图 G 是否存在环。
 * @param G
 * @return
 */
int DFSTraverse_existRing(ALGraph G) {
    for (int i = 1; i <= G.vexnum; ++i) {
        visited[i] = white;
    }
    for (int i = 1; i <= G.vexnum; ++i) {
        if(visited[i] == white) {
            int ret = DFS_existRing(G, i);
            if(ret) {
                return TRUE;
            }
        }
    }
    return FALSE;
}


void initVisited(int vexnum) {
    for (int i = 1; i <= vexnum; ++i) {
        visited[i] = FALSE;
    }
}


/**
 * 例题8、编写算法判断以邻接表方式存储的有向图 G是否存在srcVertex 到 destVertex 的路径。
 * @param G
 * @param src
 * @param dest
 * @return
 */
int existRoute(ALGraph G, VertexType src, VertexType dest) {
    visited[src] = TRUE;
    if(src == dest) {
        return TRUE;
    }
    ArcNode *nextArc = G.vertices[src].firstarc;
    while(nextArc != NULL) {
        if(visited[nextArc->adjvex] == FALSE) {
            int ret = existRoute(G, nextArc->adjvex, dest);
            if(ret) {
                return TRUE;
            }
        }
        nextArc = nextArc->nextarc;
    }
    return FALSE;
}



void printRoute(VertexType routeStack[], int routeLength) {
    printf("route: ");
    for (int i = 0; i < routeLength; ++i) {
        printf("%d ", routeStack[i]);
    }
    printf("\n");
}

VertexType routeStack[MAX_VERTEX_NUM] = {0};
int routeLength = 0;


/**
 * 例题9: 设计算法，求出以邻接表存储的有向图中所有从顶点v到顶点w的简单路径
 * @param G
 * @param v
 * @param w
 */
void findAllRoute(ALGraph G, VertexType v, VertexType w) {
    visited[v] = TRUE;
    routeStack[routeLength++] = v;
    if(v == w) {
        printRoute(routeStack, routeLength);
    }
    ArcNode *nextArc = G.vertices[v].firstarc;
    while(nextArc != NULL) {
        if(visited[nextArc->adjvex] == FALSE) {
            findAllRoute(G, nextArc->adjvex, w);
        }
        nextArc = nextArc->nextarc;
    }
    routeLength--;
    visited[v] = FALSE;
}

int length = 0;


void printRoute(VertexType routeStack[]) {
    printf("route: ");
    for (int i = 0; i < length + 1; ++i) {
        printf("%d ", routeStack[i]);
    }
    printf("\n");
}
/**
 * 例题10、设计算法求解以邻接表存储的有向图 G中所有从顶点v到顶点w长度为d的路径。
 * @param G
 * @param d   路径长度
 * @param v
 * @param w
 */
void findRouteLengthD(ALGraph G, int d, int v, int w) {
    visited[v] = TRUE;
    routeStack[routeLength++] = v;
    if(d == 0 && v == w) {
        printRoute(routeStack);
    }
    ArcNode *nextArc = G.vertices[v].firstarc;
    while(nextArc != NULL) {
        if(visited[nextArc->adjvex] == FALSE) {
            findRouteLengthD(G, d - 1, nextArc->adjvex, w);
        }
        nextArc = nextArc->nextarc;
    }
    visited[v] = FALSE;
    routeLength--;
}


VertexType topologyStack[MAX_VERTEX_NUM];
int topologyLength = 0;
/**
 * 例题 11(辅助函数)、设计算法对有向无环图 G 进行拓扑排序。
 * @param G
 * @param v
 */
void topologySort(ALGraph G, VertexType v) {
    visited[v] = TRUE;
    ArcNode *nextNode = G.vertices[v].firstarc;
    while(nextNode != NULL) {
        if(!visited[nextNode->adjvex]) {
            topologySort(G, nextNode->adjvex);
        }
        nextNode = nextNode->nextarc;
    }
    topologyStack[topologyLength++] = v;
}

/**
 * 例题 11、 设计算法对有向无环图 G 进行拓扑排序。
 * @param G
 */
void topology_DFS(ALGraph G) {
    for (int i = 1; i <= G.vexnum; ++i) {
        if(!visited[i]) {
            topologySort(G, i);
        }
    }
    printf("TopologySort: ");
    for(int i = G.vexnum - 1; i >= 0; i--) {
        printf("%d ", topologyStack[i]);
    }
}


VertexType path[MAX_VERTEX_NUM] = {-1};
int distance[MAX_VERTEX_NUM] = {INF};
int isAdded[MAX_VERTEX_NUM] = {FALSE};

int isAllAdded(int vexnum) {
    for (int i = 1; i <= vexnum; ++i) {
        if(isAdded[i] == FALSE) {
            return FALSE;
        }
    }
    return TRUE;
}

//例题12、求有向带权网N中srcVertex 到其余顶点的最短路径，并将最短路径打印输出。
void dijkstra(MGraph G, VertexType src) {
    //将起始节点接入并更新路径
    for (int i = 1; i <= G.vexnum; ++i) {
        isAdded[i] = FALSE;
        if(G.arcs[src][i].adj != INF) {
            distance[i] = G.arcs[src][i].adj;
            path[i] = src;
        }else {
            distance[i] = INF;
            path[i] = -1;
        }
    }
    isAdded[src] = TRUE;

    distance[src] = 0;
    while(!isAllAdded(G.vexnum)) {
        //找最短
        int min = INF;
        int v = -1;
        for (int i = 1; i <= G.vexnum; ++i) {
            if(isAdded[i] == FALSE && distance[i] < min) {
                min = distance[i];
                v = i;
            }
        }
        if(v == -1) {
            break;
        }
        //更新最短路径
        isAdded[v] = TRUE;
        for (int i = 1; i <= G.vexnum; ++i) {
            if(G.arcs[v][i].adj != INF && distance[v] + G.arcs[v][i].adj < distance[i]) {
                distance[i] = distance[v] + G.arcs[v][i].adj;
                path[i] = v;
            }
        }
    }
}



void printPath(MGraph G, int src) {
    for (int i = 1; i <= G.vexnum; ++i) {
        int k = i;
        if(k == src) continue;
        printf("path:%d -> %d:", src, k);
        printf("%d ", i);
        while(path[k] != src && path[k] != -1) {
            printf("%d ", path[k]);
            k = path[k];
        }
        printf("%d ", src);
        printf("\ndistance = %d\n", distance[i]);
    }
}
































void initRoute(int d) {
    routeLength = 0;
    length = d;
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
                printf("%d\t", G.arcs[i][j].adj);
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






typedef struct {
    VertexType v;       //当前顶点
    int index;          //记录其来源顶点位置
    int level;          //记录广度遍历的层数
}QElemType;


void printShortestPath(QElemType *queue, int vexnum) {
    VertexType path[MAX_VERTEX_NUM];
    int length;
    int index;
    for(int i = 1; i <= vexnum; i++) {
        if(queue[i].index == -1) {
            printf("不可达\n");
            continue;
        }
        index = i;
        length = 1;
        do {
            path[length++] = queue[index].v;
            index = queue[index].index;
        } while (index != -1);
        printf("%d -> %d: ", path[length - 1], path[1]);
        for (int j = length - 1; j >= 1; --j) {
            printf("%d ", path[j]);
        }
        printf("\n");
    }
}

//使用DFS计算有向图G从顶点v出发到各个顶点的最短路径
void shortestPath(ALGraph G, VertexType v) {
    QElemType queue[MAX_VERTEX_NUM];
    int qLength = 1;
    int cur = 1;
    int visited[MAX_VERTEX_NUM] = {0};

    queue[qLength].v = v;
    queue[qLength].index = -1;
    visited[v] = 1;
    qLength++;


    while(cur < qLength) {
        QElemType node = queue[cur];

        ArcNode *nextArc = G.vertices[node.v].firstarc;
        while(nextArc != NULL) {
            if(!visited[nextArc->adjvex]) {
                queue[qLength].v = nextArc->adjvex;
                queue[qLength].index = cur;
                visited[queue[qLength].v] = 1;
                qLength++;
            }
            nextArc = nextArc->nextarc;
        }

        cur++;
    }
    for (int i = 1; i <= G.vexnum; ++i) {
        if(!visited[i]) {
            queue[qLength].v = i;
            queue[qLength].index = -1;
            qLength++;
        }
    }


    printShortestPath(queue, G.vexnum);
}


void printPathK(QElemType queue[MAX_VERTEX_NUM], int vexnum, int w, int k) {
    VertexType path[MAX_VERTEX_NUM];
    int index = 0;
    for (int i = 1; i <= vexnum; ++i) {
        if(queue[i].v == w) {
            if(queue[i].level == k + 1) {
                int ptr = i;
                do{
                    path[index++] = queue[ptr].v;
                    ptr = queue[ptr].index;
                }while(ptr != -1);
                printf("path:");
                for (int j = index - 1; j >= 0; --j) {
                    printf("%d ", path[j]);
                }
                return;
            }else {
                printf("不存在为 %d 的最短路径.\n", k);
                return;
            }
        }
    }
    printf("不连通");
}



//给定邻接表存储的有向图G,设计算法输出一条顶点v到顶点w之间的最短路径长度为k的路径
void shortestPathK(ALGraph G, VertexType v, VertexType w, int k) {
    QElemType queue[MAX_VERTEX_NUM];
    int qLength = 1;
    int cur = 1;
    int visited[MAX_VERTEX_NUM] = {0};

    queue[qLength].v = v;
    queue[qLength].index = -1;
    queue[qLength].level = 1;
    visited[v] = 1;
    qLength++;

    while(cur < qLength){
        QElemType node = queue[cur];


        ArcNode *nextArc = G.vertices[node.v].firstarc;
        while(nextArc != NULL) {
            if(!visited[nextArc->adjvex]) {
                visited[nextArc->adjvex] = 1;
                queue[qLength].v = nextArc->adjvex;
                queue[qLength].index = cur;
                queue[qLength].level = queue[cur].level + 1;
                qLength++;
            }
            nextArc = nextArc->nextarc;
        }

        cur++;
    }

    for (int i = 1; i <= G.vexnum; ++i){
        if(!visited[i]) {
            queue[qLength].v = i;
            queue[qLength].index = -1;
            queue[qLength].level = -1;
            qLength++;
        }
    }

    printPathK(queue,G.vexnum, w, k);
}













void printAllPathK(QElemType queue[MAX_VERTEX_NUM], int length, int k) {
    VertexType path[MAX_VERTEX_NUM];
    int index = 0;
    for (int i = 1; i < length; ++i) {
        index = 0;
        if(queue[i].level == k) {
            int ptr = i;
            do{
                path[index++] = queue[ptr].v;
                ptr = queue[ptr].index;
            }while(ptr != -1);
            printf("path:");
            for (int j = index - 1; j >= 0; --j) {
                printf("%d ", path[j]);
            }
        }
        printf("\n");
    }
}



/**
 * 问题描述:求从顶点v出发长度为K的所有最短路径
 * 算法思想:使用BFS遍历图,使用队列保存路径,在遍历每一层节点时,暂时不将下一层节点入队,而是在本层节点遍历完后才入队
 * @param G
 * @param k
 */

#define MAX_SIZE 100
void allPathLengthK(ALGraph G, VertexType v, int k) {
    int visited[MAX_SIZE] = {0};
    QElemType queue[MAX_SIZE];
    int length = 0;
    int index = 0;

    queue[length].v = v;
    queue[length].level = 1;
    queue[length].index = -1;   //-1代表出发节点
    visited[v] = 1;
    length++;

    int preLevel = 1;
    while(index < length) {
        QElemType nextQueue[MAX_SIZE];
        int nextLength = 0;
        preLevel = queue[index].level;
        while(index < length && preLevel == queue[index].level) {           //保存下一层所有邻接节点
            ArcNode *nextArc = G.vertices[queue[index].v].firstarc;
            while(nextArc != NULL) {
                if(!visited[nextArc->adjvex]) {
                    nextQueue[nextLength].v = nextArc->adjvex;
                    nextQueue[nextLength].level = queue[index].level +1;
                    nextQueue[nextLength].index = index;
                    nextLength++;
                }
                nextArc = nextArc->nextarc;
            }
            preLevel = queue[index].level;
            index++;
        }
        for (int i = 0; i < nextLength; ++i){                               //将下一层入队
            queue[length].v = nextQueue[i].v;
            queue[length].level = nextQueue[i].level;
            queue[length].index = nextQueue[i].index;
            length++;
            visited[nextQueue[i].v] = 1;
        }

    }

    for (int i = 1; i <= G.vexnum; ++i){        //处理非联通节点
        if(!visited[i]) {
            queue[length].v = i;
            queue[length].index = -1;
            queue[length].level = -1;
            length++;
        }
    }
    printAllPathK(queue, length, k);

}















































