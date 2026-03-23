/*
A pair(arr[i], arr[j]) forms an inversion when i<j and arr[i]>arr[j]
For ex:-
    [2,4,1,3,5]
    (4,1),(4,3),(2,1) --> 3 Inversions
*/
#include <iostream>

using namespace std;

int naive(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }
    return count;
}

int countAndMerge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[m + 1 + i];
    }
    int res = 0, i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }else {
            arr[k] = R[j];
            j++;
            res += n1-i;
            k++;
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
    return res;
}

int best(int arr[], int low, int high) {
    int res = 0;
    if (low < high) {
        int mid = low + (high - low) / 2;
        res += best(arr, low, mid);
        res += best(arr, mid + 1, high);
        res += countAndMerge(arr,low,mid,high);
    }
}

int main() {
    int a[]{2,4,1,3,5};
    int n = sizeof(a) / sizeof(a[0]);
    // cout << naive(a, n) << endl; // theta(n**2)
    cout << best(a,0,n-1) << endl; // O(nlogn) and O(n)
}