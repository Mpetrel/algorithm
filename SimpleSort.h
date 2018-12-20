//
// Created by Mamba on 2018/12/14.
//

#ifndef SORT_SIMPLESORT_H
#define SORT_SIMPLESORT_H

#include <algorithm>

using namespace std;

class SimpleSort {
public:
    static void selectSort(int arr[], int n) {
        for (int i = 0 ; i < n ; i ++) {
            int minIndex = i;
            for (int j = i + 1 ; j < n ; j ++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    }

    static void insertSort(int arr[], int n) {
        for (int i = 1 ; i < n ; i ++) {
            int temp = arr[i];
            int j;
            for (j = i ; j > 0 && temp < arr[j - 1]; j --) {
                arr[j] = arr[j - 1];
            }
            arr[j] = temp;
        }
    }

    // 对arr 从[l, r]部分进行插入排序
    static void insertSort(int arr[], int l, int r) {
        for (int i = l + 1; i <= r; i ++) {
            int temp = arr[i];
            int j;
            for (j = i; j > l && temp < arr[j - 1]; j--) {
                arr[j] = arr[j - 1];
            }
            arr[j] = temp;
        }
    }

    static void bubbleSort(int arr[], int n) {
        for(int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < n - i - 1 ; j ++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};

#endif //SORT_SIMPLESORT_H
