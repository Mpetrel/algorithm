//
// Created by Mamba on 12/20/2018.
//

#ifndef SORT_COMPLEXSORT_H
#define SORT_COMPLEXSORT_H

#include <iostream>
#include <algorithm>

using namespace std;

class ComplexSort {
public:
    static void mergeSort(int arr[], int n) {
        __mergeSort(arr, 0, n - 1);
    }

    // 自底向上归并
    static void mergeSortBU(int arr[], int n) {

    }

    static void quickSort(int arr[], int n) {
        __quickSort(arr, 0, n - 1);
    }

private:
    //////////////////Merge Sort////////////////////////////
    static void __mergeSort(int arr[], int l, int r) {
        // if (l >= r) return;
        // 优化2 当数组小到一定程度，由于数组几乎有序，使用快速排序效率更高
        if (r - l <= 15) {
            SimpleSort::insertSort(arr, l, r);
            return;
        }
        // 相当于 （l + r)/2;防止越界
        int mid = l + (r - l) / 2;
        __mergeSort(arr, l, mid);
        __mergeSort(arr, mid + 1, r);
        // 优化1，添加此判断，由于两边都有序，所以如果不满足此条件则不用归并
        if (arr[mid] > arr[mid + 1])
            __merge(arr, l, mid, r);

    }
    // 进行归并
    static void __merge(int arr[], int l, int mid, int r) {
        int *aux = new int[r - l + 1];
        // 复制一份元素
        for (int i = l; i <= r; i ++) {
            aux[i - l] = arr[i];
        }
        // 开始归并
        int i = l, j = mid + 1;
        for (int k = l; k <= r; k ++) {
            if (i > mid) {
                arr[k] = aux[j - l];
                j ++;
            } else if (j > r) {
                arr[k] = aux[i - l];
                i ++;
            }else if (aux[i - l] > aux[j - l]) {
                arr[k] = aux[j - l];
                j ++;
            } else {
                arr[k] = aux[i - l];
                i ++;
            }
        }
        delete[] aux;
    }
    /////////////////////Merge sort end//////////////////
    /////////////////////Quick sort//////////////////////

    static void __quickSort(int arr[], int l, int r) {
        if (l >= r) return;
        int p = __partition(arr, l, r);
        __quickSort(arr, l, p);
        __quickSort(arr, p + 1, r);
    }

    static int __partition(int arr[], int l, int r) {
        int v = arr[l];
        int j = l;
        for (int i = l + 1; i <= r; i ++) {
            if (arr[i] < v) {
                swap(arr[j + 1], arr[i]);
                j ++;
            }
        }
        swap(arr[l], arr[j]);
        return j;
    }


    ////////////////////Quick sort end////////////////////

};

#endif //SORT_COMPLEXSORT_H
