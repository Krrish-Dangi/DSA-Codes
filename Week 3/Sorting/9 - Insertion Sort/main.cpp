#include <iostream>

using namespace std;


// O(n**2), in-place, stable, used for small arrays (TimSort and IntraSort) and in Best Case O(n) for Sorted Array
void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

int main() {
    int arr[]{20,5,40,60,10,30};
    int n = sizeof(arr) / sizeof(arr[0]);
    InsertionSort(arr, n);
    cout << "Sorted array is: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}