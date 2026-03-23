#include <iostream>
using namespace std;

int BinarySearch(int arr[], int low, int high, int k) {
    while (low <= high) {
        int mid = (low+high) / 2;
        if (arr[mid] == k) return mid;
        else if (arr[mid] > k) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int find(int arr[], int size, int x) {
    if (arr[0] == x) return 0;

    int i = 1;
    while (i < size && arr[i] < x) {
        i = i * 2;
    }

    if (i < size && arr[i] == x) return i;

    int low = i / 2 + 1;
    int high = min(i - 1, size - 1);

    return BinarySearch(arr, low, high, x);
}

int main() {
    int arr[] = {
        2, 4, 6, 8, 10,
        12, 14, 16, 18, 20,
        22, 24, 26, 28, 30,
        32, 34, 36, 38, 40,
        42, 44, 46, 48, 50,
        52, 54, 56, 58, 60,
        62, 64, 66, 68, 70,
        72, 74, 76, 78, 80,
        82, 84, 86, 88, 90,
        92, 94, 96, 98, 100
    };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << find(arr, size, 14) << endl;
}
