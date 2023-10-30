//
// Created by maicaoboy on 2023/10/17.
//
#include <stdio.h>
#include <stdlib.h>

// 获取数组中的最大值
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// 使用计数排序对数组按指定位数进行排序
void countSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    // 计算数字出现的次数
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // 将计数数组累加，以确定每个数字在输出数组中的位置
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // 从后向前遍历原数组，根据计数数组确定每个数字在输出数组中的位置
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // 将排序后的结果复制回原数组
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// 基数排序函数
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // 从最低位到最高位，依次对数组进行计数排序
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
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
