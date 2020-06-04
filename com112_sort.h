#ifndef COM112_SORT_H
#define COM112_SORT_H


void bubbleSort(int arr[],int n,int* compara,int* trocas);
void selectionSort(int arr[],int n,int* compara,int* trocas);
void insertionSort(int arr[],int n,int* compara,int* trocas);
void mergeSort(int arr[], int left, int right,int quantidade,int *compara,int* trocas);
void quickSort(int arr[], int low, int high,int* compara,int* trocas);

#endif