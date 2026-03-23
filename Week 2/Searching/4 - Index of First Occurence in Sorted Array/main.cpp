#include <iostream>

using namespace std;

int IterativeFind(int arr[], int n, int x){
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

int RecursiveFind(int arr[], int low, int high, int x) {
    if (low > high) {
        return -1;
    }
    int mid = (low+high)/2;
    if (x > arr[mid]) {
        return RecursiveFind(arr, mid+1, high, x);
    }else if (x < arr[mid]) {
        return RecursiveFind(arr, low, mid-1, x);
    }else {
        if (mid == 0 || arr[mid-1] != arr[mid]) {
            return mid;
        }else {
            return RecursiveFind(arr, low, mid-1, x);
        }
    }
}

int main() {
    int arr[]{5,10,10,15,20,20,20};
    cout << RecursiveFind(arr, 0, 5, 20) << endl;
    cout << IterativeFind(arr,5,20) << endl;
}
