#include <iostream>
#include "SortTestHelper.h"
#include "SimpleSort.h"
#include "ComplexSort.h"

using namespace std;

int main() {
    int n = 5000000;
    int* arr = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr2 = SortTestHelper::copyIntArray(arr, n);
    SortTestHelper::testSort("quickSort", ComplexSort::quickSort, arr, n);
    SortTestHelper::testSort("mergeSort", ComplexSort::mergeSort, arr2, n);

    delete[] arr;
    delete[] arr2;
}