#include <iostream>

using namespace std;

int BinarySearch(int arr[], int k, int low, int high) {
    if (low > high) {
        return -1;
    }

    int mid = (low+high)/2;
    if (arr[mid] == k) {
        return mid;
    }else if (arr[mid] > k) {
        return BinarySearch(arr,k,low,mid-1);
    }else {
        return BinarySearch(arr,k,mid+1,high);
    }
}

int main() {
    int arr[]{15,23,31,45,57};
    cout << BinarySearch(arr,23,0,4) << endl; // O(logn) and O(logn)
}