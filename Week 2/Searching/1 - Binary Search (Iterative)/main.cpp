#include <iostream>

using namespace std;

// Sorted Array
int BinarySearch(int arr[], int n, int k) {
    int low = 0, high = n-1;
    while (low <= high) {
        int mid = (low+high)/2;
        if (arr[mid] == k) return mid;
        else if (arr[mid] > k) high = mid-1;
        else if (arr[mid] < k) low = mid+1;
    }
    return -1;
}

int main() {
    int arr[]{10,20,30,40,50,60,70};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << BinarySearch(arr,n,50) << endl; // O(logn)

    return 0;
}