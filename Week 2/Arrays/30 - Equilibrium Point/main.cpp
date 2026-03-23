// Equilibrium point --> aage piche elements ka sum euqal ho

#include <iostream>

using namespace std;

bool naive(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int lSum{};
        int rSum{};
        for (int j = 0; j < i; j++) {
            lSum += arr[j];
        }

        for (int k = i + 1; k < n; k++) {
            rSum += arr[k];
        }

        if (lSum == rSum) {
            return true;
        }
    }
    return false;
}

bool best(int arr[], int n) {
    int rs = 0;
    for (int i = 0; i < n; i++) {
        rs += arr[i];
    }

    int ls = 0;
    for (int i = 0; i < n; i++) {
        rs -= arr[i];
        if (ls == rs) {
            return true;
        }
        ls += arr[i];
    }
    return false;
}

int main() {
    int arr[]{4,2,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << boolalpha;
    cout << naive(arr, n) << endl; // theta(n**2)

    int arr1[]{4,2,2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    // cout << boolalpha;
    cout << naive(arr1, n1) << endl; // theta(n)
}