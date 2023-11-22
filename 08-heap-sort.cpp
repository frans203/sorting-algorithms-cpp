#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    cout << "[ ";
    for (int i = 0;i<n;i++){
        cout << arr[i] << " ";
    }

    cout << "]";
}

//rooted with node i, wich is an index in arr. N is the size of heap
//This function is max heaping the arry
void heapify(int arr[], int N, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < N && arr[left] > arr[largest]) {
        largest = left;
    }

    if(right < N && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }

}

void heapSort(int arr[], int n){
    //building heap
    for (int i=n/2 - 1;i>=0;i--){ //this first index, i=n/2 - 1, it is this way because like that we can
    // be more efficient, and prevent doing unnecessary comparions, considering all internal nodes, and not considering
    // leaf nodes, wich already fulfill the requirement of the heap, having no left or right children
        heapify(arr, n, i);
    }

    for(int i=n-1;i>0;i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


int main() {
    int arr[] = {1,33,512,5,198, 0, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    heapSort(arr, n);
    printArray(arr, n);
    return 0;
}