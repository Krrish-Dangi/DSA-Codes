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
    if (l < h) {
        int pivot = HoarePartition(arr, l, h);
        QuickSort(arr, l, pivot); //***
        QuickSort(arr, pivot+1, h);
    }
}

int main() {
    int arr[]{8, 4, 7, 9, 3, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    QuickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}