#include <iostream>

using namespace std;

int naive(int arr[], int n) {
    int temp[n];
    temp[0] = arr[0];
    int result = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != temp[result-1]) {
            temp[result] = arr[i];
            result++;
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    return result;
}

int best(int arr[], int n) {
    int res = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[res-1]) {
            arr[res] = arr[i];
            res++;
        }
    }
    return res;
}

int main() {
    int arr[]{10,20,20,30,30,30};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << naive(arr, n) << endl; // T.C. --> O(n) and A.S --> O(n)
    int arr1[]{10,20,20,30,30,30};
    int n1 = sizeof(arr1) / sizeof(arr[0]);
    cout << naive(arr1, n1) << endl; // T.C. --> O(n)

}