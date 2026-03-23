#include <iostream>

using namespace std;

int naive(int arr[], int n) {
    int res = arr[0];
    for (int i = 0; i < n; i++) {
        int curr_max = arr[i];
        int curr_sum = arr[i];
        for (int j = 1; j < n; j++) {
            int index = (i + j) % n;
            curr_sum += arr[index];
            curr_max = max(curr_max, curr_sum);
        }
        res = max(res, curr_max);
    }
    return res;
}

int Kaden(int arr[], int n) {
    int res = arr[0];
    int maxEnding = arr[0];
    for (int i = 1; i < n; i++) {
        maxEnding = max(maxEnding+arr[i], arr[i]);
        res = max(res, maxEnding);
    }
    return res;
}

int best(int arr[], int n) {
    int max_normal = Kaden(arr, n);
    if (max_normal < 0) return max_normal;
    int arr_sum = 0;
    for (int i = 0; i < n; i++) {
        arr_sum += arr[i];
        arr[i] = -arr[i];
    }
    int max_circular = Kaden(arr, n) + arr_sum;
    return max(max_circular, max_normal);
}

int main() {
    int arr[]{5,-2,3,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << naive(arr, n) << endl; // O(n**2)

    int arr1[]{5,-2,3,4};
    int n1 = sizeof(arr) / sizeof(arr[0]);
    cout << best(arr1, n1) << endl; // O(n)
}