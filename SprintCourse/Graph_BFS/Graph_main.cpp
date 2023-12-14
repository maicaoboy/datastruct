//
// Created by maicaoboy on 2023/11/18.
//
#include "Graph.cpp"

int main() {
    FILE *vertexFile = fopen("./SprintCourse/Graph_BFS/vertex.txt", "r");
    FILE *arcFile = fopen("./SprintCourse/Graph_BFS/arc.txt", "r");
    int vertex[MAX_VERTEX_NUM] = {0};
    int arc[MAX_VERTEX_NUM][3] = {0};



    /**
     * 测试0 读取文件
     */
    printf("\n*************** 测试0 *********************\n");



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

    shortestPath(G, 1);


    /**
     * 测试2
     */
    printf("\n*************** 测试2 *********************\n");
    shortestPathK(G, 1, 8, 4);


    /**
     * 测试2
     */
    printf("\n*************** 测试3 *********************\n");
    allPathLengthK(G, 4, 3);

    freeGraph_ALGraph(G);







}



















































