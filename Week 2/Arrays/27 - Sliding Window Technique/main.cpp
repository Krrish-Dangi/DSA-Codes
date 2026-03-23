// Finding the maximum sum of K consecutive elements

#include <iostream>

using namespace std;

int naive(int arr[], int n, int k) {
    int res = INT_MIN;
    for (int i = 0; i+k-1 < n; i++) {
        int curr = 0;
        for (int j = 0; j < k; j++) {
            curr += arr[i+j];
        }
        res =  max(res, curr);
    }
    return res;
}

int windowSlidingTechnique(int arr[], int n, int k) {
    int curr = 0;
    for (int i = 0; i < k; i++) {
        curr += arr[i];
    }
    int res = curr;
    for (int i = k; i < n; i++) {
        curr = curr - arr[i-k] + arr[i];
        res = max(res, curr);
    }
    return res;
}

int main() {
    int arr[]{10,5,-2,20,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << naive(arr, n, k) << endl; // O(n*k)

    int arr1[]{10,5,-2,20,1};
    int n1 = sizeof(arr) / sizeof(arr[0]);
    int k1 = 3;
    cout << naive(arr1, n1, k1) << endl; // O(n)
}