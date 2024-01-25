#include <bits/stdc++.h>
using namespace std;


void printArray(int array[], int n){
    cout << "[ ";
    for(int i=0;i<n;i++){
        cout << array[i] << " ";
    }
    cout << "]";

}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for(i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int array []= {10,9,8};
    int n = sizeof(array)/sizeof(array[0]);
    cout << "Sorted array:  \n";
    insertionSort(array, n);
    printArray(array, n);
    return 0;
}