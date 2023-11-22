#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> array) {
    cout << "[ ";
    for(int i=0;i<array.size();i++){
        cout << array[i] << " ";
    }

    cout << "]";
}

vector<int> countingSort(vector<int> inputArray) {
    int inputArraySize = inputArray.size();
    int maxElement = 0;
    for(int i=0;i<inputArraySize;i++){
        maxElement = max(inputArray[i], maxElement);
    }
    vector<int> countArray(maxElement + 1, 0);
    vector<int> outputArray(inputArraySize, 0);

    for(int i=0;i<inputArraySize;i++){
        countArray[inputArray[i]]++;
    }

    for(int i=1;i<=maxElement;i++){
        countArray[i] += countArray[i - 1];
    }

    for(int i=inputArraySize - 1;i>=0;i--){
        int elementInputArrayIndex = inputArray[i];
        int coutArrayElement = countArray[elementInputArrayIndex]--;
        outputArray[coutArrayElement] = elementInputArrayIndex;

    }

    return outputArray;
}


int main () {
    vector<int> inputArray = {43,89,1,0,0,0,0,2,31,2,4,2,4,89,41,23}; //verify what should happen with greatest values
    printArray(inputArray);
    vector<int> outputArray = countingSort(inputArray);
    cout << "\n";
    printArray(outputArray);
    return 0;
}