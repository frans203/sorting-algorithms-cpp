//in this version we can stop the sorting when the array is sorted
//without the need to run another time to verify it

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){
    bool isUnsorted;

    do {
        isUnsorted = false;
        for(int i=0; i < (n - 1); i++){
            if(arr[i] > arr[i + 1]){
                isUnsorted = true;
                for(; i < (n - 1); i++){
                    if(arr[i] > arr[i + 1]){
                        swap(arr[i], arr[i + 1]);
                    }
                }
            }
        }
    }while(isUnsorted);
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