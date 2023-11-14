//
// Created by maicaoboy on 2023/10/16.
//
#include "stdio.h"

int partition(int arr[], int i, int j) {
    int e = arr[i];
    while(i < j) {
        while(i < j && arr[j] >= e) {
            j--;
        }
        if(i < j) {
            arr[i] = arr[j];
            i++;
        }
        while(i < j && arr[i] < e) {
            i++;
        }
        if(i < j) {
            arr[j] = arr[i];
            j--;
        }
    }
    arr[i] = e;

    return i;
}

void quickSort(int arr[], int i, int j) {
    if(i < j) {
        int index = partition(arr, i, j);
        quickSort(arr, i, index - 1);
        quickSort(arr, index + 1, j);
    }
}

int main() {
    int arr[] = {3, 6, 8, 10, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

