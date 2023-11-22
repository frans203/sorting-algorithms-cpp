#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int partition(int arr[], int start, int end){
    int pivot = arr[start];
    int count = 0;
    for(int i=start+1;i<=end;i++){
        if(arr[i] <= pivot){
            count++;
        }
    }
    int pivotIndex = start + count;
    swap(arr[start], arr[pivotIndex]);

    //sorting left and right parts of pivot element

    int i = start; 
    int j = end;

    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot){ //continue until it found an element that is greater than the pivot, but in the left side
            i++;
        }

        while(arr[j] > pivot){ //continue until it found an element that is smaller than the pivot, but in the right side
            j--;
        }

        if(i<pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]); //swap this elements, and increase i, descrease j, because we don't need to do anything with them anymore
        }
    }

    return pivotIndex;

}

void quickSort(int arr[], int start, int end){
    if(start >= end){
        return;
    }
    int p = partition(arr, start, end);
    quickSort(arr, start, p-1);
    quickSort(arr, p + 1, end);
}



void printArray(int array[], int n){
    cout << "[ ";
    for(int i=0;i<n;i++){
        cout << array[i] << " ";
    }
    cout << "]";

}

int main() {
    int array[] = {12,3,4,4,5,62123,0,1};
    int arrayLength = sizeof(array)/sizeof(array[0]);
    quickSort(array, 0, arrayLength - 1);
    printArray(array, arrayLength);
    
}