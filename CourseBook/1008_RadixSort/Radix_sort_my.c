//
// Created by maicaoboy on 2023/10/17.
//
#include "stdio.h"
#include "stdlib.h"

int getMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i <n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void expSort(int arr[], int n, int exp) {
    int count[10] = {0};
    int *temp = malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++) {
        count[arr[i] / exp % 10]++;
    }

    for(int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for(int i = n - 1; i >= 0; i--) {
        temp[count[arr[i] / exp % 10] - 1] = arr[i];
        count[arr[i] / exp % 10]--;
    }

    for(int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    free(temp);
}


void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    for(int exp = 1; max / exp > 0; exp *= 10) {
        expSort(arr, n, exp);
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
