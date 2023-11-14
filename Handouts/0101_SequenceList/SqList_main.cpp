//
// Created by maicaoboy on 2023/10/22.
//
#include "SqList.cpp"

int main() {
    SqList L;
    int lenght = 15;
    int e;

    /**
     * 测试例题1
     */

    printf("*************** 测试1 *********************\n");
    initial(L);


    for(int i = 0; i < lenght; i++) {
        L.pList[i] = i;
    }
    L.length = lenght;


    /**
     * 测试例题2
     */
    printf("\n*************** 测试2 *********************\n");

    printf("删除前:\n");
    for(int i = 0; i < L.length; i++) {
        printf("%d ", L.pList[i]);
    }

    deleteIthItem(L, 3, e);

    printf("\n删除位置3的元素是:%d", e);
    printf("\n删除后:\n");
    for(int i = 0; i < L.length; i++) {
        printf("%d ", L.pList[i]);
    }


    /**
     * 测试例题3
     */
    printf("\n*************** 测试3 *********************\n");
    printf("\n插入e: %d 前:\n", e);
    for(int i = 0; i < L.length; i++) {
        printf("%d ", L.pList[i]);
    }

    insert(L, 3, e);

    printf("\n位置ith: 3 前插入: %d\n", e);
    for(int i = 0; i < L.length; i++) {
        printf("%d ", L.pList[i]);
    }


    /**
     * 测试例题4
     */
    printf("\n*************** 测试4 *********************\n");
    int min = 5;
    L.pList[5] = -1;

    printf("删除最小前:\n");
    for(int i = 0; i < L.length; i++) {
        printf("%d ", L.pList[i]);
    }

    deleteMin(L);

    printf("\n删除最小后:\n");
    for(int i = 0; i < L.length; i++) {
        printf("%d ", L.pList[i]);
    }

    /**
     * 测试例题5
     */

    printf("\n*************** 测试5 *********************\n");
    printf("删除4-7前:\n");
    for(int i = 0; i < L.length; i++) {
        printf("%d ", L.pList[i]);
    }

    deleteElem(L, 4, 7);

    printf("\n删除4-7后:\n");
    for(int i = 0; i < L.length; i++) {
        printf("%d ", L.pList[i]);
    }

    /**
     * 测试例题 6
     */

    printf("\n*************** 测试6 *********************\n");
    L.pList[4] = 6;

    printf("删除8-10前:\n");
    for(int i = 0; i < L.length; i++) {
        printf("%d ", L.pList[i]);
    }

    deleteELemOrder(L, 8, 10);

    printf("\n删除8-10后:\n");
    for(int i = 0; i < L.length; i++) {
        printf("%d ", L.pList[i]);
    }



    printf("\n*************** 测试7 *********************\n");
    initial(L);
    for(int i = 0; i < 10; i++) {
        L.pList[2 * i] = L.pList[2 * i + 1] = i;
    }
    L.length = 20;

    printf("删除重复元素前:\n");
    for(int i = 0; i < L.length; i++) {
        printf("%d ", L.pList[i]);
    }

    deleteELemRepeat(L);

    printf("\n删除重复元素后:\n");
    for(int i = 0; i < L.length; i++) {
        printf("%d ", L.pList[i]);
    }

    printf("\n*************** 测试8_1 *********************\n");

    printf("cbauidajdhbacdjckd");

    SqList A, B, C;
    initial(A);
    initial(B);
    initial(C);

    // Populate A and B with sorted values
    A.pList[0] = 1;
    A.pList[1] = 3;
    A.pList[2] = 5;
    A.pList[3] = 8;
    A.pList[4] = 12;
    A.length = 5;

    B.pList[0] = 9;
    B.pList[1] = 7;
    B.pList[2] = 6;
    B.pList[3] = 4;
    B.pList[4] = -1;

    B.length = 5;

    printf("合并前 A: ");
    for (int i = 0; i < A.length; i++) {
        printf("%d ", A.pList[i]);
    }
    printf("\n");

    printf("合并前 B: ");
    for (int i = 0; i < B.length; i++) {
        printf("%d ", B.pList[i]);
    }
    printf("\n");

    // Merge A and B into C
    merge_1(A, B, C);

    // Print the merged list C
    printf("合并后 C: ");
    for (int i = 0; i < C.length; i++) {
        printf("%d ", C.pList[i]);
    }
    printf("\n");




    printf("\n*************** 测试8_2 *********************\n");
    initial(A);
    initial(B);

    // Populate A and B with sorted values
    A.pList[0] = 1;
    A.pList[1] = 3;
    A.pList[2] = 5;
    A.pList[3] = 8;
    A.pList[4] = 12;
    A.length = 5;

    B.pList[0] = 9;
    B.pList[1] = 7;
    B.pList[2] = 6;
    B.pList[3] = 4;
    B.pList[4] = 2;

    B.length = 5;

    printf("合并前 A: ");
    for (int i = 0; i < A.length; i++) {
        printf("%d ", A.pList[i]);
    }
    printf("\n");

    printf("合并前 B: ");
    for (int i = 0; i < B.length; i++) {
        printf("%d ", B.pList[i]);
    }
    printf("\n");

    merge_2(A, B);

    printf("合并后 A: ");
    for (int i = 0; i < A.length; i++) {
        printf("%d ", A.pList[i]);
    }
    printf("\n");



    printf("\n*************** 测试8_3 *********************\n");
    initial(A);

    // Populate A and B with sorted values
    A.pList[0] = 1;
    A.pList[1] = 3;
    A.pList[2] = 5;
    A.pList[3] = 8;
    A.pList[4] = 12;
    A.pList[5] = 14;
    A.pList[6] = 15;
    A.pList[7] = 18;
    A.pList[8] = 18;
    A.pList[9] = 17;
    A.pList[10] = 8;
    A.pList[11] = 6;
    A.pList[12] = -1;
    A.length = 13;

    printf("合并前 A: ");
    for (int i = 0; i < A.length; i++) {
        printf("%d ", A.pList[i]);
    }
    printf("\n");

    sort(A);

    printf("合并后 A: ");
    for (int i = 0; i < A.length; i++) {
        printf("%d ", A.pList[i]);
    }
    printf("\n");




    printf("\n*************** 测试9 *********************\n");
    initial(A);
    initial(B);

    // Populate A and B with sorted values
    A.pList[0] = 1;
    A.pList[1] = 3;
    A.pList[2] = 5;
    A.pList[3] = 8;
    A.pList[4] = 12;
    A.pList[5] = 15;
    A.pList[6] = 17;
    A.pList[7] = 20;
    A.pList[8] = 40;
    A.pList[9] = 70;
    A.length = 10;

    B.pList[0] = 2;
    B.pList[1] = 5;
    B.pList[2] = 6;
    B.pList[3] = 7;
    B.pList[4] = 8;
    B.pList[5] = 11;
    B.pList[6] = 12;
    B.pList[7] = 15;
    B.pList[8] = 17;
    B.pList[9] = 30;
    B.length = 10;


    printf("求交集前 A: ");
    for (int i = 0; i < A.length; i++) {
        printf("%d ", A.pList[i]);
    }
    printf("\n");

    printf("求交集前 B: ");
    for (int i = 0; i < B.length; i++) {
        printf("%d ", B.pList[i]);
    }
    printf("\n");

    intersection(A, B);

    printf("求交集后 A: ");
    for (int i = 0; i < A.length; i++) {
        printf("%d ", A.pList[i]);
    }
    printf("\n");



    printf("\n*************** 测试10 *********************\n");
    initial(A);
    initial(B);

    // Populate A and B with sorted values
    A.pList[0] = 1;
    A.pList[1] = 3;
    A.pList[2] = 5;
    A.pList[3] = 8;
    A.pList[4] = 12;
    A.pList[5] = 15;
    A.pList[6] = 17;
    A.pList[7] = 20;
    A.pList[8] = 40;
    A.pList[9] = 70;
    A.length = 10;

    B.pList[0] = 2;
    B.pList[1] = 5;
    B.pList[2] = 6;
    B.pList[3] = 7;
    B.pList[4] = 8;
    B.pList[5] = 11;
    B.pList[6] = 12;
    B.pList[7] = 15;
    B.pList[8] = 17;
    B.pList[9] = 30;
    B.length = 10;


    printf("求差集前 A: ");
    for (int i = 0; i < A.length; i++) {
        printf("%d ", A.pList[i]);
    }
    printf("\n");

    printf("求差集前 B: ");
    for (int i = 0; i < B.length; i++) {
        printf("%d ", B.pList[i]);
    }
    printf("\n");

    difference(A, B);

    printf("求差集后 A: ");
    for (int i = 0; i < A.length; i++) {
        printf("%d ", A.pList[i]);
    }
    printf("\n");


    printf("\n*************** 测试11 *********************\n");
    initial(A);

    // Populate A and B with sorted values
    for(int i = 0; i < 15; i++) {
        A.pList[i] = i + 1;
    }
    A.length = 15;

    printf("转置前 A: ");
    for (int i = 0; i < A.length; i++) {
        printf("%d ", A.pList[i]);
    }
    printf("\n");

    reverse(A);

    printf("转置前 A: ");
    for (int i = 0; i < A.length; i++) {
        printf("%d ", A.pList[i]);
    }
    printf("\n");



    printf("\n*************** 测试12 *********************\n");
    initial(A);

    // Populate A and B with sorted values
    for(int i = 0; i < 15; i++) {
        A.pList[i] = i + 1;
    }
    A.length = 15;

    printf("左移3前 A: ");
    for (int i = 0; i < A.length; i++) {
        printf("%d ", A.pList[i]);
    }
    printf("\n");

    left_r(A, 3);

    printf("左移3后 A: ");
    for (int i = 0; i < A.length; i++) {
        printf("%d ", A.pList[i]);
    }
    printf("\n");


                







    free(L.pList);
    free(A.pList);
    free(B.pList);
    free(C.pList);
}