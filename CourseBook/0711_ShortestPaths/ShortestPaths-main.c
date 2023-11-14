#include <stdio.h>
#include "MGraph.h"
#include "ShortestPaths.h"

void djs(MGraph G) {
    int i;
    PathMatrix P;
    ShortPathTable D;
    ShortestPath_DIJ_Net_PathMatrix(G, 0, P, D);
    for (i=1; i<G.vexnum; i++) {
        printf("V%d - V%d的最短路径中的顶点有(逆序)：",0,i);
        if(D[i] != INFINITE) {
            printf(" V%d",i);
            int j=i;
            //由于每一段最短路径上都记录着经过的顶点，所以采用嵌套的方式输出即可得到各个最短路径上的所有顶点
            while (P[j]!=0) {
                printf(" V%d",P[j]);
                j=P[j];
            }
            printf(" V0\n");
        }else {
            printf("不连通\n");
        }
    }
    printf("源点到各顶点的最短路径长度为:\n");
    for (i=1; i<G.vexnum; i++) {
        printf("V%d - V%d : %d \n",G.vexs[0],G.vexs[i],D[i]);
    }
}

int main(int argc, char* argv[]) {
    MGraph G;
    
    printf("████████ 创建并打印无向图/网... \n");
    {
        char* path[4];
        
        path[0] = "TestData_DG.txt";
        path[1] = "TestData_DN.txt";
        path[2] = "TestData_UDG.txt";
        path[3] = "TestData_UDN.txt";
        
        CreateGraph(&G, path);
        PrintGraph(G);
    }
    PressEnterToContinue(debug);
    
    printf("████████ 迪杰斯特拉算法求单源最短路径... \n");
    {
        VertexType v0 = 'A';
        PathMatrix_DIJ P;
        ShortPathTable_DIJ D;
        
        printf("输出从顶点 %c 到其余顶点的最短路径：\n", v0);
        ShortestPath_DIJ(G, LocateVex(G, v0), P, D);
        PrintPath_DIJ(G, LocateVex(G, v0), P, D);
    }
    PressEnterToContinue(debug);
    
    printf("████████ 弗洛伊德算法求多源最短路径... \n");
    {
        PathMatrix_FLOYD P;
        ShortPathTable_FLOYD D;
        
        printf("输出各对顶点之间的最短路径：\n");
        ShortestPath_FLOYD(G, P, D);
        PrintPath_FLOYD(G, P, D);
    }
    PressEnterToContinue(debug);

    djs(G);
    
}
