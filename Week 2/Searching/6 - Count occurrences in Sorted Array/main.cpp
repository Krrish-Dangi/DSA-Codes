#include <iostream>

using namespace std;

int FindFirst(int arr[], int n, int x) {
    int low = 0;
    int high = n-1;
    while (low <= high) {
        int mid = (low+high)/2;
        if (arr[mid] > x) {
            high = mid - 1;
        }else if (arr[mid] < x) {
            low = mid + 1;
        }else {
            if (mid == 0 || arr[mid - 1] != arr[mid]) {
                return mid;
            }else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int FindLast(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > x) {
            high = mid - 1;
        }else if (arr[mid] < x) {
            low = mid + 1;
        }else {
            if (mid == 0 || arr[mid + 1] != arr[mid]) {
                return mid;
            }else {
                low = mid + 1;
            }
        }
    }
    return -1;
}

int count(int arr[], int n, int x) {
    int first = FindFirst(arr,n,x);
    if (first == -1) {
        return 0;
    }else {
        return (FindLast(arr,n,x) - first + 1);
    }
}

int main() {
    int arr[]{10,20,20,20,30,30};
    cout << count(arr, sizeof(arr)/sizeof(arr[0]), 20) << endl;
}