/*
File name: sorting.hpp
Author: Michael C. Chavrimootoo
Last Updated: 01/22/2025
Creation Date: 01/17/2025
Description: Templated declarations for the required sorting functions & helpers.
*/


#pragma once
#include <iostream>
#include <random>

// Modern C++ for random numbers see block comment below for usage
// Next line specifies the random number generator to use
// Place here to not reinitialize with every function call
std::mt19937 generator(std::random_device{}());
// this way we just need to do some math and not re initialize a distribution every time
std::uniform_real_distribution<> unif(0, 1); // initializes a uniform distribution over [0,1)
/*
To use the above to generate a random integer from a to b (inclusive):
int randNum = unif(generator)*(b-a+1) + a; // supplies `generator` to distribution and generates the random number, and scales the random real to the [a,b] range
*/




template<class T>
void insertionSort(T *A, int n);


template<class T>
void merge(T* A, int p, int q, int r);


template<class T>
void mergeSort(T *A, int p, int r);


template<class T>
int partition(T *A, int p, int r);


template<class T>
void quickSort(T *A, int p, int r);


template<class T>
int randomizedPartition(T *A, int p, int r);


template<class T>
void randomizedQuickSort(T *A, int p, int r);
