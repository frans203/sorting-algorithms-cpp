#include <bits/stdc++.h>
#include <iostream>
using namespace std;


void merge(int arr[], int const left, int const mid, int const right){
    int const subArrayLeft = mid - left + 1;
    int const subArrayRight = right - mid;

    int *leftArray = new int[subArrayLeft];
    int *rightArray = new int[subArrayRight];
    
    for(int i=0;i<subArrayLeft;i++){
        leftArray[i] = arr[left + i];
    }

    for(int i=0;i<subArrayRight;i++){
        rightArray[i] = arr[mid + i + 1];
    }

    int indexSubArrayOne = 0;
    int indexSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while(indexSubArrayOne < subArrayLeft && indexSubArrayTwo < subArrayRight){
        if(leftArray[indexSubArrayOne] <= rightArray[indexSubArrayTwo]){
            arr[indexOfMergedArray] = leftArray[indexSubArrayOne];
            indexSubArrayOne++;
        }else{
            arr[indexOfMergedArray] = rightArray[indexSubArrayTwo];
            indexSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while(indexSubArrayOne < subArrayLeft){
        arr[indexOfMergedArray] = leftArray[indexSubArrayOne];
        indexOfMergedArray++;
        indexSubArrayOne++;
    }

    while(indexSubArrayTwo < subArrayRight){
        arr[indexOfMergedArray] = rightArray[indexSubArrayTwo];
        indexOfMergedArray++;
        indexSubArrayTwo++;
    }
    delete[] leftArray;
    delete[] rightArray;   
}

void mergeSort(int arr[], int const begin, int const end ){
    if(begin >= end){
        return;
    }
    int mid = begin + (end - begin)/2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}


void printArray(int array[], int n){
    cout << "[ ";
    for(int i=0;i<n;i++){
        cout << array[i] << " ";
    }
    cout << "]";

}

int main() {
    int arr[] = {1,335, 5,99,322,12,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, n-1);
    printArray(arr, n);
    return 0;
}