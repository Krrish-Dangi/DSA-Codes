#include <iostream>

using namespace std;

int naive(int arr[], int n) {
    int res = 0;
    for (int i = 1; i < n-1; i++) {
        int Lmax = arr[i];
        for (int j = 0; j < i; j++) {
            Lmax = max(Lmax, arr[j]);
        }
        int Rmax = arr[i];
        for (int j = i+1; j < n; j++) {
            Rmax = max(Rmax, arr[j]);
        }

        res = res + min(Lmax,Rmax) - arr[i];
    }

    return res;
}

int best(int arr[], int n) {
    int res = 0;
    int Lmax[n], Rmax[n];
    Lmax[0] = arr[0];
    for (int i = 1; i < n; i++) {
        Lmax[i] = max(arr[i], Lmax[i-1]);
    }

    Rmax[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--) {
        Rmax[i] = max(arr[i], Rmax[i+1]);
    }

    for (int i = 1; i < n-1; i++) {
        res = res + min(Lmax[i-1], Rmax[i+1]) - arr[i];
    }
    return res;
}

int main() {
    int arr[]{3,0,1,2,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << naive(arr, n); // theta(n**2)

    cout << endl;

    int arr1[]{3,0,1,2,5};
    int n1 = sizeof(arr) / sizeof(arr[0]);
    cout << best(arr1, n1); // theta(n) and theta(n)




}