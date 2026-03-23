#include <iostream>

using namespace std;

int naive(bool arr[], int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = i; j < n; j++) {
            if (arr[j] != 1) {
                break;
            }
            count++;
        }
        if (max < count) {
            max = count;
        }
    }
    return max;
}

int best(bool arr[], int n) {
    int res = 0;
    int curr = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) curr = 0;
        else {
            curr++;
            res = max(res, curr);
        }
    }
}




int main() {
    bool arr[]{0,0,0,0,0,1,1,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << naive(arr, n) << endl; // O(n**2)

    bool arr1[]{0,0,0,0,0,1,1,1};
    int n1 = sizeof(arr) / sizeof(arr[0]);
    cout << naive(arr1, n1) << endl; // theta(n)
}