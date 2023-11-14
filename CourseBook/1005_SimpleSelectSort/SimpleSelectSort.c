//
// Created by maicaoboy on 2023/10/17.
//
#include "stdio.h"


void SelectSort(int arr[], int length) {
    int i, j, min, temp;

    for(i = 0; i < length; i++) {
        min = i;
        for(j = i; j < length; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main() {
    int arr[] = {6,1,8,34,89,12,56,3,8,4,1};
    int length = 11;

    printf("排序前:\n");
    for(int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }

    SelectSort(arr, length);

    printf("\n排序后:\n");
    for(int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
}
