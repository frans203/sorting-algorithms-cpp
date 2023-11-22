#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int partition(int *arr, int start, int end){
    int index = 0, pivotElement = arr[end], pivotIndex = 0;
    int* temp = new int[end - start + 1];

    for(int i =start;i<=end;i++){
        if(arr[i] < pivotElement){
            temp[index] = arr[i];
            index++;
        }
    }
    temp[index] = pivotElement;
    index++;

    for(int i=start;i< end;i++){
        if(arr[i] > pivotElement){
            temp[index] = arr[i];
            index++;
        }
    }

    index=0;
    for(int i=start;i<=end; i++){
        if(arr[i] == pivotElement){
            pivotIndex = i;
        }
        arr[i] = temp[index];
        index++;
    }

    return pivotIndex;

}

void quickSort(int *arr, int start, int end){
    if(start < end){
        int partitionIndex = partition(arr, start, end);
        quickSort(arr, start, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, end);
    }
    return;
}


void printArray(int array[], int n){
    cout << "[ ";
    for(int i=0;i<n;i++){
        cout << array[i] << " ";
    }
    cout << "]";

}

int main () {
    int arr[] = {5,14,1,4,2,8,23,12,399,9}; //for some reason isn't possible to use double elements
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, size-1);
    printArray(arr, size);
    return 0;
}