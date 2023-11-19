//
// Created by maicaoboy on 2023/11/18.
//
#include "Graph.cpp"

int main() {
    FILE *vertexFile = fopen("./Handouts/0501_Graph/vertex.txt", "r");
    FILE *arcFile = fopen("./Handouts/0501_Graph/arc.txt", "r");
    FILE *vertexFile_ring = fopen("./Handouts/0501_Graph/vertex_ring.txt", "r");
    FILE *arcFile_ring = fopen("./Handouts/0501_Graph/arc_ring.txt", "r");
    int vertex[MAX_VERTEX_NUM] = {0};
    int arc[MAX_VERTEX_NUM][3] = {0};
    int vertex_ring[MAX_VERTEX_NUM] = {0};
    int arc_ring[MAX_VERTEX_NUM][3] = {0};



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

    int vexnum_ring = 0;
    if(vertexFile_ring != NULL) {
        while(!feof(vertexFile_ring)) {
            fscanf(vertexFile_ring, "%d", &vertex_ring[vexnum_ring]);
            vexnum_ring++;
        }
    }

    int arcnum_ring = 0;
    if(arcFile_ring != NULL) {
        while(!feof(arcFile_ring)) {
            fscanf(arcFile_ring, "%d %d %d", &arc_ring[arcnum_ring][0], &arc_ring[arcnum_ring][1], &arc_ring[arcnum_ring][2]);
            arcnum_ring++;
        }
    }

    fclose(vertexFile_ring);
    fclose(arcFile_ring);

    printf("Vextex_ring: ");
    for(int i = 0; i < vexnum_ring; i++) {
        printf("%d ", vertex_ring[i]);
    }
    printf("\nArc_ring: \n");
    for(int i = 0; i < arcnum_ring; i++) {
        printf("%d %d\n", arc_ring[i][0], arc_ring[i][1]);
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
    DFSTraverse(G);
    printf("\n");
    freeGraph_ALGraph(G);


    /**
     * 测试7
     */
    printf("\n*************** 测试7 *********************\n");
    createALGraph_DG(G, vertex, vexnum, arc, arcnum);
    int ret = DFSTraverse_existRing(G);
    printGragh(G);
    freeGraph_ALGraph(G);
    if(ret) {
        printf("exist ring\n");
    }else {
        printf("no ring\n");
    }

    createALGraph_DG(G, vertex_ring, vexnum_ring, arc_ring, arcnum_ring);
    ret = DFSTraverse_existRing(G);
    printGragh(G);
    freeGraph_ALGraph(G);
    if(ret) {
        printf("exist ring\n");
    }else {
        printf("no ring\n");
    }


    /**
     * 测试8
     */
    printf("\n*************** 测试8 *********************\n");
    createALGraph_DG(G, vertex_ring, vexnum_ring, arc_ring, arcnum_ring);
    printGragh(G);
    initVisited(G.vexnum);
    int src = 4, dest = 1;
    ret = existRoute(G, src, dest);
    if(ret) {
        printf("%d -> %d 的路存在\n", src, dest);
    }else {
        printf("%d -> %d 的路不存在\n", src, dest);
    }
    initVisited(G.vexnum);
    src = 1;
    dest = 8;
    ret = existRoute(G, src, dest);
    if(ret) {
        printf("%d -> %d 的路存在\n", src, dest);
    }else {
        printf("%d -> %d 的路不存在\n", src, dest);
    }
    freeGraph_ALGraph(G);



    /**
     * 测试9
     */
    printf("\n*************** 测试9 *********************\n");
    createALGraph_DG(G, vertex_ring, vexnum_ring, arc_ring, arcnum_ring);
    printGragh(G);
    initVisited(G.vexnum);
    initRoute(-1);
    int v = 1, w = 4;
    printf("%d -> %d 的路径有:\n", v, w);
    findAllRoute(G, v, w);
    printf("\n");
    v = 7, w = 5;
    printf("%d -> %d 的路径有:\n", v, w);
    findAllRoute(G, v, w);
    printf("\n");
    freeGraph_ALGraph(G);


    /**
     * 测试10
     */
    printf("\n*************** 测试10 *********************\n");
    createALGraph_DG(G, vertex_ring, vexnum_ring, arc_ring, arcnum_ring);
    printGragh(G);
    initVisited(G.vexnum);
    v = 1, w = 4;
    int d = 2;
    printf("%d -> %d 长度为 %d 的路径有:\n", v, w, d);
    initRoute(d);
    findRouteLengthD(G, d, v, w);
    printf("\n");
    freeGraph_ALGraph(G);




    /**
     * 测试11
     */
    printf("\n*************** 测试11 *********************\n");
    createALGraph_DG(G, vertex, vexnum, arc, arcnum);
    printGragh(G);
    topology_DFS(G);
    freeGraph_ALGraph(G);


    /**
     * 测试12
     */
    printf("\n*************** 测试12 *********************\n");
    createALGraph_DN(G, vertex_ring, vexnum_ring, arc_ring, arcnum_ring);
    converseARCNetToMNet(G, G2);
    printGragh(G);
    printGragh_mG(G2);
    src = 1;
    dijkstra(G2, src);
    printPath(G2, src);
    freeGraph_ALGraph(G);
}



















































