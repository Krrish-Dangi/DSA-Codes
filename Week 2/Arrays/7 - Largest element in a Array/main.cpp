#include <iostream>

using namespace std;

int max(int arr[], int len) {
    int max1 = arr[0];
    int index{0};
    for (int i = 0; i < len; i++) {
        if (arr[i] > max1) {
            max1 = arr[i];
            index = i;
        }
    }
    return index;
}

int main() {
    int arr[] = {10, 29, 38, 47, 56, 65, 74, 83, 92, 101};
    cout << "Index of maximum element: " << max(arr, 10) << endl; //theta(len)
}