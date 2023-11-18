//
// Created by maicaoboy on 2023/11/18.
//
#include "Graph.cpp"

int main() {
    FILE *vertexFile = fopen("./Handouts/0501_Graph/vertex.txt", "r");
    FILE *arcFile = fopen("./Handouts/0501_Graph/arc.txt", "r");
    int vertex[MAX_VERTEX_NUM] = {0};


    /**
     * 测试0 读取文件
     */
    printf("\n*************** 测试0 *********************\n");


    int arc[MAX_VERTEX_NUM][3] = {0};

    int vexnum = 0;
    if(vertexFile != NULL) {
        while(!feof(vertexFile)) {
            fscanf(vertexFile, "%d", &vertex[vexnum]);
            vexnum++;
        }
    }

    int arcnum = 0;
    if(arcFile != NULL) {
        while(!feof(arcFile)) {
            fscanf(arcFile, "%d %d %d", &arc[arcnum][0], &arc[arcnum][1], &arc[arcnum][2]);
            arcnum++;
        }
    }

    fclose(vertexFile);
    fclose(arcFile);

    printf("Vextex: ");
    for(int i = 0; i < vexnum; i++) {
        printf("%d ", vertex[i]);
    }
    printf("\nArc: \n");
    for(int i = 0; i < arcnum; i++) {
        printf("%d %d\n", arc[i][0], arc[i][1]);
    }



    /**
     * 测试1
     */
    printf("\n*************** 测试1 *********************\n");
    ALGraph G;
    createALGraph_UDG(G, vertex, vexnum, arc, arcnum);
    printGragh(G);
    printf("\n");

    ALGraph G1;
    createALGraph_DG(G1, vertex, vexnum, arc, arcnum);
    printGragh(G1);
    freeGraph_ALGraph(G);
    freeGraph_ALGraph(G1);




    /**
     * 测试2
     */
    printf("\n*************** 测试2 *********************\n");
    createALGraph_DG(G, vertex, vexnum, arc, arcnum);
    reverseALGraph(G, G1);
    printf("G:\n");
    printGragh(G);
    printf("\n");
    printf("G1:\n");
    printGragh(G1);
    printf("\n");
    freeGraph_ALGraph(G);
    freeGraph_ALGraph(G1);




    /**
     * 测试3
     */
    printf("\n*************** 测试3 *********************\n");
    createALGraph_DG(G, vertex, vexnum, arc, arcnum);
    int degree[MAX_VERTEX_NUM + 1];
    degreeAlGraph_DG(G, degree);
    printf("degree: ");
    for (int i = 1; i <= G.vexnum; ++i) {
        printf("%d ", degree[i]);
    }
    printf("\n");
    freeGraph_ALGraph(G);



    /**
     * 测试4
     */
    printf("\n*************** 测试4 *********************\n");
    createALGraph_UDG(G, vertex, vexnum, arc, arcnum);
    printf("G:\n");
    printGragh(G);
    printf("\n");
    deleteArc_UDG(G, 2, 4);
    printf("G:\n");
    printGragh(G);
    printf("\n");
    freeGraph_ALGraph(G);


    /**
     * 测试5
     */
    printf("\n*************** 测试5 *********************\n");
    MGraph G2;
    createALGraph_DN(G, vertex, vexnum, arc, arcnum);
    printGragh(G);
    converseARCNetToMNet(G, G2);
    printGragh_mG(G2);


    /**
     * 测试6
     */
    printf("\n*************** 测试6 *********************\n");
    createALGraph_DN(G, vertex, vexnum, arc, arcnum);
    printGragh(G);
    DFS(G);
    printf("\n");
    freeGraph_ALGraph(G);

}



















































