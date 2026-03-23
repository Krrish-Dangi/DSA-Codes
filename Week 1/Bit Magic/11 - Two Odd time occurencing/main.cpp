#include <iostream>

using namespace std;

void naive(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count%2 != 0) {
            cout << arr[i] << endl;
        }
    }
}

void best(int arr[], int n) {
    int x = arr[0];
    for (int i = 1; i < n; i++) {
        x = x ^ arr[i];
    }

    int k = (x & ~(x - 1)); // rightmost set bit
    int res1 = 0, res2 = 0;
    for (int i = 0; i < n; i++) {
        if ((arr[i] & k) != 0) {
            res1 = res1 ^ arr[i];
        }else {
            res2 = res2 ^ arr[i];
        }
    }
        cout << res1 << " ";
        cout << res2 << endl;
}

int main() {
    int arr[]{1,1,1,2,2,2,3,4,3,4};
    naive(arr,10); // theta(n**2)

    cout << endl;
    best(arr,10);


    return 0;
}