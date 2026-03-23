#include <iostream>

using namespace std;

int naive(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int count = 1;
        for (int j = i+1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > size/2) {
            return i;
        }
    }
    return -1;
}

int mooresVotingAlgo(int arr[], int size) {
    int res = 0; int count = 1;
    for (int i = 1; i < size; i++) {
        if (arr[res] == arr[i]) {
            count++;
        }else count--;
        if (count == 0) {
            res = i;
            count = 1;
        }
    }

    count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == arr[res]) {
            count++;
        }
        if (count <= size/2) {
            res = -1;
        }
    }

    return res;
}

int main() {
    int arr[]{8,7,8,6,8,6,6,6,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << naive(arr, size) << endl; // O(n**2)

    int arr1[]{8,7,8,6,8,6,6,6,6};
    int size1 = sizeof(arr)/sizeof(arr[0]);
    cout << mooresVotingAlgo(arr1, size1) << endl; // O(n)


}