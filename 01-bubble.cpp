#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int arr[], int n) {
    int i, j;
    for(i=0;i < n;i++){ //iterates over the array
        for(j = 0; j < n - i - 1; j++){ //iterates over the unsorted amout of the array
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void printArray(int arr[], int size){
    int i;
    cout << "[";
    for(i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    
    cout << "]" << endl;
}

int main() {
    int arr[] = {5,1,3, 9,4, 7, 123, 990, 2};
    int N = (sizeof(arr)/ sizeof(arr[0]));
    bubbleSort(arr, N);
    cout << "Sorted array: \n";
    printArray(arr, N);
    return 0;
}