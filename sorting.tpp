/*
sorting.tpp
A file that contains the implementation of the sorting methods in the sorting.hpp file.
Written by: Khoi V, Duc T.
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "sorting.hpp"

using namespace std;

// Insertion sort function.
// Parameters: array A (passed by reference), number of elements (n) in list A.
// Return value: None.
// Runtime:
// Best case scenario: O(n) (when the list is already sorted).
// Worst case scenario: O(n^2).
// Written by: Khoi V.
template <class T>
void insertionSort(T *A, int n) {
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

// Merge function implementation for the merge sort function.
// Description: This function merge two sorted sub-arrays into one totally sorted (sub-)array and replace it in the original array.
// Parameters: Original array A (passed by reference), the first index of the first sub array p,
// the last index of the first sub array q, the last index of the second sub array r.
// Return value: None.
// Written by: Khoi V.
template<class T>
void merge(T* A, int p, int q, int r){
    T S[r - p + 1];
    int i = p;
    int j = q + 1;
    int k = 0;
    while (i <= q && j <= r){
        if (A[i] <= A[j]){
            S[k] = A[i];
            i++;
        } else {
            S[k] = A[j];
            j++;
        }
        k++;
    }
    while (i <= q) {
        S[k] = A[i];
        k++;
        i++;
    }
    while (j <= r) {
        S[k] = A[j];
        k++;
        j++;
    }
    for (int x = 0; x <= r - p; x++) {
        A[p + x] = S[x];
    }
}

// Merge sort function.
// Parameters: array A (passed by reference), the first index of the array (p), the last index of the array (r).
// Return value: None.
// Runtime:
// Best case scenario: O(n log n).
// Worst case: O(n log n).
// This function has a better runtime than the insertion sort function.
// Written by: Khoi V.
template<class T>
void mergeSort(T *A, int p, int r) {
    // Base case: if p = r, the array has only one element and is already sorted.
    // Otherwise, this function runs recursively on the sub-arrays.
    if (p < r) {
        int q = p + (r - p) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

// Partition function.
// Description: This function partitions the part from A[p] to A[r] by choosing A[r]
// as the pivot and puts all value smaller than it to its left, then puts all value larger than it to its right
// and puts the pivot in its correct position.
// Parameter: Original array A (passed by reference), the first and last index (p and r) of the part of array to be partitioned.
// Return value: None.
// Written by: Duc T.
template<class T>
int partition(T *A, int p, int r){
    int swap_index = p;
    T pivot = A[r];
    for (int i = p;i < r;i++){
        if (A[i] < pivot){
            swap(A[swap_index], A[i]);
            swap_index ++;
        }
    }
    swap(A[swap_index], A[r]);
    return swap_index;
}

// Quick sort function.
// Parameters: array A (passed by reference), the first index of the array (p), the last index of the array (r).
// Return value: None.
// Runtime:
// Best case scenario: O(n log n).
// Worst case: O(n^2).
// Written by: Duc T.
template<class T>
void quickSort(T *A, int p, int r){
    // Base case: if p = r, the array has only one element and is already sorted.
    // Otherwise, this function runs recursively on the sub-arrays.
    if (p < r){
        int pivot = partition(A,p,r);
        quickSort(A,p,pivot-1);
        quickSort(A,pivot+1,r);
    }
}

// Randomized partition function.
// Description: This function partitions the part from A[p] to A[r] by choosing a random pivot in range
// and puts all value smaller than it to its left, then puts all value larger than it to its right
// and puts the pivot in its correct position.
// Parameter: Original array A (passed by reference), the first and last index (p and r) of the part of array to be partitioned.
// Return value: None.
// Written by: Duc T.
template<class T>
int randomizedPartition(T *A, int p, int r){
    int randNum = unif(generator)*(r-p+1) + p;
    swap(A,randNum,r);
    int swap_index = p;
    T pivot = A[r];
    for (int i = p;i < r;i++){
        if (A[i] < pivot){
            swap(A, swap_index, i);
            swap_index ++;
        }
    }
    swap(A,swap_index,r);
    return swap_index;
}

// Quick sort function.
// Parameters: array A (passed by reference), the first index of the array (p), the last index of the array (r).
// Return value: None.
// Runtime:
// Best case scenario: O(n log n).
// Worst case: O(n^2) (this is extremely rare since the pivot is chosen randomly).
// Written by: Duc T.
template<class T>
void randomizedQuickSort(T *A, int p, int r){
    if (p < r){
        int pivot = partition(A,p,r);
        quickSort(A,p,pivot-1);
        quickSort(A,pivot+1,r);
    }
}