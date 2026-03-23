#include <algorithm>
#include <iostream>

using namespace std;

int computeDifference(int arr[], int n) {
    sort(arr, arr + n);
    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        res = min(res, abs(arr[i] - arr[i + 1]));
    }
    return res;
}

int main() {
    int arr[]{2,3231413,3141,242,13123};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << computeDifference(arr, n) << endl; // O(nlogn)
}