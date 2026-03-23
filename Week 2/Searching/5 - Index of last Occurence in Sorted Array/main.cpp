#include <iostream>

using namespace std;

int LastOccurence(int arr[], int size, int x) {
    int low = 0, high = size - 1;
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

int main() {
    int arr[]{10,15,20,20,40,40};
    cout << LastOccurence(arr, 6, 20) << endl;
}