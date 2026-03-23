#include <iostream>
using namespace std;

void countingSort(int arr[], int n, int exp) {
    int count[10] = {0};   // initialize all to 0
    int output[n];

    // Count occurrences of digits
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Convert count[i] to prefix sum (cumulative count)
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build output array (stable sorting, right-to-left)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy back to arr
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void RadixSort(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) mx = arr[i];
    }

    // Do counting sort for every digit
    for (int exp = 1; mx / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

int main() {
    int arr[]{319, 212, 6, 8, 100, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    RadixSort(arr, n); // theta(digit*(n+b)) and theta(n+b) and stable

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
