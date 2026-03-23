// Quick Select Algorithm

#include <iostream>

using namespace std;

int lPartition(int arr[], int l, int h) {
    int pivot = arr[h];
    int i = l - 1;
    for (int j = l; j <= h-1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[h]);
    return (i + 1);
}

int find(int arr[], int l, int h, int k) {
    while (true) {
        int p = lPartition(arr, l, h);
        if (p == k-1) {
            return arr[p];
        }else if (p > k-1) {
            h = p - 1;
        }else {
            l = p + 1;
        }
    }
}

int main() {
    int arr[]{2,4,5,53,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << find(arr, 0, n-1, 3) << endl; // Same T.C. as QuickSort
}