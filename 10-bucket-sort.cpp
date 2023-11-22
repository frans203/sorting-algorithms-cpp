#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void printArray(float array[],  int n) {
    cout << "[ ";
    for(int i=0;i<n;i++){
        cout << array[i] << " ";
    }

    cout << "]\n";
}

void bucketSort(float arr[], int n){
    vector<float> buckets[n]; //creating n empty buckets
    for(int i=0;i<n;i++){
        //adding elements 
        int bucketIndex = arr[i] * n;
        buckets[bucketIndex].push_back(arr[i]);
    }

    for(int i=0;i<n;i++){
        sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<buckets[i].size();j++){
            arr[index] = buckets[i][j];
            index++;
        }
    }

}


int main() {
    float arr[] = {0.45, 0.42,0.11,0.3, 0.56, 0.99, 0.01};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    bucketSort(arr, n);
    printArray(arr, n);

    return 0;
}