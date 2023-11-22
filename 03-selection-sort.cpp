#include <bits/stdc++.h>
using namespace std;

void printArray(int array[], int n){
    cout << "[ ";
    for(int i=0;i<n;i++){
        cout << array[i] << " ";
    }
    cout << "]";

}

void selectionSort(int arr[], int n){
    int i, j, min_index;
    for(i =0;i < n - 1;i++){
        min_index = i;
        for(j = i + 1;j<n;j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }

        if(min_index != i){
            swap(arr[min_index], arr[i]);
        }

    }

}

int main(){
    int array[] = {33,44,9,1,3,25};
    int n = sizeof(array)/sizeof(array[0]);

    selectionSort(array, n);
    cout << "Sorted array: \n";
    printArray(array, n);

    return 0;
}