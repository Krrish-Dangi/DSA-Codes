#include <iostream>

using namespace std;

int HoarePartition(int arr[], int l, int h) {
    int pivot = arr[l];
    int i = l-1;
    int j = h+1;
    while (true) {
        do {
            i++;
        }while (arr[i] < pivot);

        do {
            j--;
        }while (arr[j] > pivot);

        if (i >= j) {
            return j;
        }
        swap(arr[i], arr[j]);
    }
}

void QuickSort(int arr[], int l, int h) {
    Begin:
    if (l < h) {
        int pivot = HoarePartition(arr, l, h);
        QuickSort(arr, l, pivot);
        l = pivot+1;
        goto Begin;
    }
}

int main() {
    int arr[]{24,45,6,42,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    QuickSort(arr, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}