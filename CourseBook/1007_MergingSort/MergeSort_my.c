//
// Created by maicaoboy on 2023/10/18.
//
#include "stdio.h"
#include "stdlib.h"

void merge(int arr[], int left, int middle, int right) {
    int n1, n2, i, j, k;

    n1 = middle - left + 1;
    n2 = right - middle;

    int *arr1 = malloc(sizeof(int) * n1);
    int *arr2 = malloc(sizeof(int) * n2);

    for(i = 0; i < n1; i++) {
        arr1[i] = arr[left + i];
    }

    for(j = 0; j < n2; j++) {
        arr2[j] = arr[middle + j + 1];
    }

    for(k = left, i = 0, j = 0; i < n1 && j < n2; k++) {
        if(arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            i++;
        }else {
            arr[k] = arr2[j];
            j++;
        }
    }

    while(i < n1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = arr2[j];
        k++;
        j++;
    }

    free(arr1);
    free(arr2);
}


void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

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