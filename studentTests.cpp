#include <iostream>
#include "sorting.hpp"
#include "sorting.tpp"

using namespace std;

int main () {
    // Test Insertion Sort
    // Expected output: 1 2 3 4 5 6 7 8 9 10 11
    int arr[11] = {11, 2, 4, 5, 7, 6, 9, 8, 1, 3, 10};
    int n = 11;
    insertionSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Test Merge Sort
    // Expected output: 1 2 3 4 5 6 7 8 9 10 11
    int arr2[11] = {11, 2, 4, 5, 7, 6, 9, 8, 1, 3, 10};
    int n2= 11;
    mergeSort(arr2, 0, n2 - 1);
    for (int i = 0; i < n2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    // Test Quick Sort
    // Expected output: 1 2 3 4 5 6 7 8 9 10 11
    int arr3[11] = {11, 2, 4, 5, 7, 6, 9, 8, 1, 3, 10};
    int n3= 11;
    quickSort(arr3, 0, n3 - 1);
    for (int i = 0; i < n3; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;

    // Test Randomized Quick Sort
    // Expected output: 1 2 3 4 5 6 7 8 9 10 11
    int arr4[11] = {11, 2, 4, 5, 7, 6, 9, 8, 1, 3, 10};
    int n4= 11;
    randomizedQuickSort(arr4, 0, n4 - 1);
    for (int i = 0; i < n4; i++) {
        cout << arr4[i] << " ";
    }
    cout << endl;

    return 0;
}