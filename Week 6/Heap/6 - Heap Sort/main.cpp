// STEP 1 -> BUILD MAX HEAP
// STEP 2 -> REPEATEDLY SWAP ROOT WITH LEAST NODE, REDUCE HEAP SIZE BY ONE, AND HEAPIFY
#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i) {
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    int i = (n-2)/2;
    while (i >= 0) {
        maxHeapify(arr, n, i);
        i--;
    }
}

void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n);
    for (int i = n-1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {50, 20, 10, 4, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}