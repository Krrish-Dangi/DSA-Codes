#include <iostream>

using namespace std;

void Reverse(int arr[], int n) {
    cout << "[";
    for (int i = n-1; i >= 0; i--) {
        if (i == 0) {
            cout << arr[i];
        }else {
            cout << arr[i] << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Reverse(arr, 10); // theta(n)
}