#include <iostream>

using namespace std;

void naive(int arr[], int n) {
    int temp[n];
    int i = 0;
    for (int j = 0; j < n; j++) {
        if (arr[j] < 0) {
            temp[i] = arr[j];
            i++;
        }
    }

    for (int j = 0; j < n; j++) {
        if (arr[j] >= 0) {
            temp[i] = arr[j];
            i++;
        }
    }

    for (int j = 0; j < n; j++) {
        arr[j] = temp[j];
    }
}

void best(int arr[], int n) {
    int i = -1, j = n;
    while (true) {
        do {
            i++;
        }while (arr[i] < 0);

        do {
            j--;
        }while (arr[j] >= 0);
        if (i >= j) {
            return;
        }
        swap(arr[i], arr[j]);
    }
}

int main() {
    int arr[]{13,-12,18,-10};
    int n = sizeof(arr) / sizeof(arr[0]);
    // naive(arr, n); // theta(n) and theta(n)
    best(arr, n); // theta(n) and theta(1)
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}