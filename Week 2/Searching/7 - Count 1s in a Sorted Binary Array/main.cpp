#include <iostream>

using namespace std;

int FindFirst(bool arr[], int n, int x) {
    int low = 0;
    int high = n-1;
    while (low <= high) {
        int mid = (low+high)/2;
        if (arr[mid] != x) {
            low = mid + 1;
        }else {
            if (mid == 0 || arr[mid - 1] != 1) {
                return mid;
            }else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int findOnes(bool arr[], int n) {
    int index = FindFirst(arr, n, 1);
    if (index != -1) {
        return n-index;
    }else {
        return 0;
    }
}

int main() {
    bool arr[]{0,0,0,0,0};
    cout << findOnes(arr, 5);
}