#include <iostream>

using namespace std;

int getLargest(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = i;
        }
    }
    return max;
}

int getSecondLargest(int arr[], int n) {
    int max = getLargest(arr, n);
    int res = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] != arr[max]) {
            if (res == -1) {
                res = i;
            }else if (arr[i] > arr[res]) {
                res = i;
            }
        }
    }
    return res;
}

int best(int arr[], int n) {
    int max {};
    int res {-1};
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[max]) {
            res = max;
            max = i;
        }else if (arr[i] != arr[max]) {
            if (res == -1 || arr[i] > arr[res]) {
                res = i;
            }
        }
    }
    return res;
}

int main() {
    int array[]{5,10,12,20,150};
    cout << getSecondLargest(array, 5) << endl; // METHOD 1 (NAIVE) --> theta(n**2)
    cout << best(array, 5) << endl; // METHOD 2 (BEST) --> theta(n)
}