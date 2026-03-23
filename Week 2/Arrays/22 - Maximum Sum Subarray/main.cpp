#include <iostream>

using namespace std;

int naive(int arr[], int n) {
    int res = arr[0];
    for (int i = 0; i < n; i++) {
        int curr = 0;
        for (int j = i; j < n; j++) {
            curr += arr[j];
            res = max(res, curr);
        }
    }
    return res;
}

int best(int arr[], int n) {
    int res = arr[0];
    int maxEnding = arr[0];
    for (int i = 1; i < n; i++) {
        maxEnding = max(maxEnding + arr[i], arr[i]);
        res = max(res, maxEnding);
    }
    return res;
}

int main() {
    int arr[]{1,-2,3,-1,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << naive(arr, n) << endl; // O(n**2)

    int arr1[]{1,-2,3,-1,2};
    int n1 = sizeof(arr) / sizeof(arr[0]);
    cout << best(arr1, n1) << endl; // O(n)
}