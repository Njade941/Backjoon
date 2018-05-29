#include <iostream>
using namespace std;

void divide (int* arr, int* left, int* right, int n) {
    int mid = n/2;

    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < n; i++) {
        right[i - mid] = arr[i];
    }
}

void merge (int* arr, int* left, int* right, int start, int leftN, int rightN) {
    int arrIndex = start;
    int leftIndex = 0;
    int rightIndex = 0;

    while (leftIndex < leftN && rightIndex < rightN) {
        if (left[leftIndex] < right[rightIndex]) {
            arr[arrIndex] = left[leftIndex];
            leftIndex++;
        }
        else {
            arr[arrIndex] = right[rightIndex];
            rightIndex++;
        }
        arrIndex++;
    }

    while (leftIndex < leftN) {
        arr[arrIndex] = left[leftIndex];
        arrIndex++;
        leftIndex++;
    }
    while(rightIndex < rightN) {
        arr[arrIndex] = right[rightIndex];
        arrIndex++;
        rightIndex++;
    }
}


void mergeSort (int* arr, int start, int end, int n) {
    if (n <= 1) {
        return;
    }
    
    int left[n/2];
    int right[n - n/2];
    
    divide (arr, left, right, n);
    mergeSort (left, 0, n/2, n/2);
    mergeSort (right, 0, n - n/2, n - n/2);
    merge (arr, left, right, start, n/2, n - n/2);
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    mergeSort(a, 0, n, n);
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }
}