#include <iostream>

using namespace std;

bool check(int arr[], int n, int x) {
    for (int k = 0; k < n-2; k++) {
        int i = k+1, j = n-1;
        int sum = x-arr[k];
        while (i <= j) {
            if (arr[i] + arr[j] == sum) {
                return true;
            }else if (arr[i] + arr[j] > sum) {
                j--;
            }else {
                i++;
            }
        }
    }
    return false;
}

int main() {
    int arr[]{2,3,4,8,9,20,40};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << boolalpha;
    cout << check(arr, n, 32) << endl; // O(n**2)
}