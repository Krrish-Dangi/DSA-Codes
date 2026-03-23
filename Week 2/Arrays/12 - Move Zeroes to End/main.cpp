#include <iostream>
using namespace std;

void best(int arr[], int n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[res]);
            res++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[]{10,20};
    int n = sizeof(arr) / sizeof(arr[0]);
    best(arr, n); // O(n)
}
