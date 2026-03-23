#include <iostream>

using namespace std;

void leftRotate(int arr[], int n) {
    int temp = arr[0];
    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

void naive(int arr[], int n, int d) {
    for (int i = 0; i < d; i++) {
        leftRotate(arr, n);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void better(int arr[], int n, int d) {
    int temp[d];
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    for (int i = d; i < n; i++) {
        arr[i-d] = arr[i];
    }

    for (int i = 0; i < d; i++) {
        arr[n-d+i] = temp[i];
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void reverse(int arr[], int low, int high) {
    while (low < high) {
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}

void best(int arr[], int n, int d) {
    reverse(arr, 0, d-1);
    reverse(arr, d, n-1);
    reverse(arr, 0, n-1);

}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    naive(arr, n, 2); // theta(n**2)

    cout << endl;

    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n1 = sizeof(arr) / sizeof(arr[0]);
    better(arr1, n1, 2); // theta(n)

    cout << endl;

    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n2 = sizeof(arr) / sizeof(arr[0]);
    better(arr1, n1, 2); // theta(n) and theta(d)

    cout << endl;

    int arr3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n3 = sizeof(arr) / sizeof(arr[0]);
    best(arr3, n3, 2); // theta(n)

}