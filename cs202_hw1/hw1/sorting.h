/*
* Title: Sorting and Algorithm Efficiency
* Author: Tarýk Buðra Karali
* ID: 21703937
* Section: 1
* Assignment: 1
*/
#ifndef sorting_h
#define sorting_h

#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
#include <time.h>  // for timer
#include <stdlib.h>  //rand
#include <iomanip>
using namespace std;



void selectionSort(int *arr, const int size, int &compCount, int &moveCount);

void mergeSort(int *arr, int size, int &compCount, int &moveCount);

void quickSort(int *arr, int size, int &compCount, int &moveCount);

void radixSort(int *arr, int size);


void displayArray(int *arr, int size);

void performanceAnalysis();

int indexOfLargest(int theArray[], int size) ;

void merge( int theArray[], int first, int mid, int last);

void mergesort(int *arr, int first, int last, int &compCount, int &moveCount);

void quicksort(int *theArray, int first, int last, int &compCount, int &moveCount);

void partition(int *theArray, int first, int last, int &pivotIndex, int &compCount, int &moveCount);

void swap(int &a, int &b);


int numDigits(int number);
int findMax(int *theArray, int n);
void radixSort(int *arr, int n, int numDigits);
void createArrays(int *arr1, int *arr2, int *arr3, int *arr4, int size);


void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
#endif
