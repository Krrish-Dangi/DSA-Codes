#include <iostream>

using namespace std;

bool isSorted(int arr[], int n) {
    bool flag = true;
    for (int i = 0; i < n-1; i++) {
        if (arr[i] > arr[i + 1]) {
            flag = false;
            break;
        }
    }
    return flag;
}

int main() {
    int arr[] = {100, 20, 200};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << boolalpha;
    cout << isSorted(arr, n) << endl; // O(n)
}