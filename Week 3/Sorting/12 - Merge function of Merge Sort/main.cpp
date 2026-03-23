#include <iostream>

using namespace std;

void MergeFunction(int arr[], int low, int mid, int high, int n) {
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

    for (int k = 0; k < n; k++) {
        cout << arr[k] << " ";
    }

}

int main() {
    int arr[]{10,15,20,40,8,11,55};
    int n = sizeof(arr) / sizeof(arr[0]);
    MergeFunction(arr, 0, 3, 6, n); // O(n1+n2) and O(n1+n2)
}

