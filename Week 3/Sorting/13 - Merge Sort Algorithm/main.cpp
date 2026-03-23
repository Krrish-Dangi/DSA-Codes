#include <iostream>

using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
            k++;
        }else {
            arr[k] = R[j];
            k++;
            j++;
        }
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}

void MergeSort(int arr[], int low, int high) {
    if (high > low) { // At least 2 element
        int mid = low + ((high - low) / 2); // Same as (low + high)/2
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        merge(arr,low,mid,high);
    }
}

int main() {
    int arr[]{10,5,30,15,7};
    MergeSort(arr, 0, 4); // O(nlogn) and O(n)
    for (auto elem: arr) {
        cout << elem << " ";
    }
}