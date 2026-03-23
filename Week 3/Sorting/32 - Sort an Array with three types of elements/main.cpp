#include <iostream>

using namespace std;

void DutchNationalFlagAlgo(int arr[], int n) {
    int low = 0, high = n - 1, mid = 0;
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }else if (arr[mid] == 1) {
            mid++;
        }else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    int arr[]{0,1,2,1,1,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    DutchNationalFlagAlgo(arr, n); // theta(n) and theta(1)
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}