#include <iostream>
using namespace std;

int getMax(int arr[], int n){
    int maxValue = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i] > maxValue){
            maxValue = arr[i];
        }
    }
    return maxValue;
}

void printArray(int array[], int n){
    cout << "[ ";
    for(int i=0;i<n;i++){
        cout << array[i] << " ";
    }
    cout << "]\n";

}


void coutingSort(int arr[], int n, int exp){
    int outputArray[n];
    int i;
    int countArray[10] = { 0 };  //10 is sufficient to store all the ocorrencies because we are sorting by units, tens, hundreds 

    for(i=0;i<n;i++){
        countArray[(arr[i] / exp) % 10]++;
    }

    for(i=1;i<10;i++){
        countArray[i] += countArray[i - 1];
    }

    for(i=n-1;i>=0;i--){
        int elementFromInputArr = arr[i];
        int countArrayElement = countArray[(elementFromInputArr/exp) % 10]-1; //*
        outputArray[countArrayElement] = elementFromInputArr;

        countArray[(elementFromInputArr/exp) % 10]--;
    }

    for(i=0;i<n;i++){
        arr[i] = outputArray[i];
    }
}

void radixSort(int arr[], int n){
    int maxValue = getMax(arr, n);

    for(int i = 1; maxValue/i > 0 ; i*=10){
        coutingSort(arr, n, i);
    }
}

int main() {
    int arr[] ={ 143, 999, 98, 12, 2, 4, 5, 2, 13, 4, 6, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    radixSort(arr, n);
    printArray(arr, n);
    return 0;
}