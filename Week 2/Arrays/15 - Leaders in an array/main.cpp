// Element which is largest amongst the right side of its elements

#include <iostream>

using namespace std;

void naive(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int flag = false;
        for (int j = i+1; j < n; j++) {
            if (arr[i] <= arr[j]) {
                flag = true;
                break;
            }
        }
        if (flag == false) {
            cout << arr[i] <<  " ";
        }
    }
}

void best(int arr[], int n) {
    int leader = arr[n-1];
    cout << leader << " ";
    for (int i = n-2; i >= 0; i--) {
        if (leader < arr[i]) {
            leader = arr[i];
            cout << leader << " ";
        }
    }
}


int main() {
    int arr[]{7,10,4,10,6,5,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    naive(arr, n); // O(n**2)

    cout << endl;

    int arr1[]{7,10,4,10,6,5,2};
    int n1 = sizeof(arr) / sizeof(arr[0]);
    best(arr, n1); // O(n)

}