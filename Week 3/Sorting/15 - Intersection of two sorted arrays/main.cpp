#include <iostream>
#include <math.h>

using namespace std;

void naive(int a[], int b[], int m, int n) {
    for (int i = 0; i < m; i++) {
        if (i > 0 && a[i] == a[i-1]) continue;
        for (int j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                cout << a[i] << " ";
                break;
            }
        }
    }
}

void best(int a[], int b[], int m, int n) {
    int i = 0, j =0;
    while (i < m && j < n) {
        if (i > 0 && a[i] == a[i-1]) {
            i++;
            continue;
        }
        if (a[i] < b[j]) {
            i++;
        }else if (a[i] > b[j]) {
            j++;
        }else {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
}

int main() {
    int arr[]{1,20,20,40,60};
    int m = sizeof(arr) / sizeof(arr[0]);
    int arr2[]{2,20,20,20};
    int n = sizeof(arr2) / sizeof(arr2[0]);
    // naive(arr, arr2, m, n); // O(m*n)
    best(arr, arr2, m, n); // O(min(m,n))
}
