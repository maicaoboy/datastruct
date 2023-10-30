//
// Created by maicaoboy on 2023/10/17.
//
#include "stdio.h"

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // 创建临时数组来存放分割后的子数组
    int* leftArr = (int*)malloc(n1 * sizeof(int));
    int* rightArr = (int*)malloc(n2 * sizeof(int));

    // 复制数据到临时数组 leftArr[] 和 rightArr[]
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[middle + 1 + j];

    // 合并临时数组到 arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // 复制 leftArr[] 的剩余部分
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // 复制 rightArr[] 的剩余部分
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    // 释放临时数组
    free(leftArr);
    free(rightArr);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        // 分别对左半部分和右半部分进行归并排序
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // 合并两个子数组
        merge(arr, left, middle, right);
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
