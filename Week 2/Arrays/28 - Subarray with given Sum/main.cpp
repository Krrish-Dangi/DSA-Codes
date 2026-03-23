// No negative elements

#include <iostream>

using namespace std;

bool naive(int arr[], int n, int sum3) {
    bool flag{};
    for (int i = 0; i < n; i++) {
        int check{};
        for (int j = i; j < n; j++) {
            check += arr[j];
            if (check == sum3) {
                flag = true;
                break;
            }
        }
    }
    return flag;
}

bool best(int arr[], int n, int sum3) {
    int s = 0;
    int curr = 0;
    for (int e = 0; e < n; e++) {
        curr += arr[e];
        while (sum3 < curr) {
            curr -= arr[curr];
            s++;
        }
        if (curr == sum3) {
            return true;
        }
    }
    return false;
}

int main(){
    int arr[]{3,2,0,4,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum2 = 6;
    cout << boolalpha;
    cout << naive(arr, n, sum2) << endl; // O(n**2)

    int arr1[]{3,2,0,4,7};
    int n1 = sizeof(arr1) / sizeof(arr[0]);
    int sum1 = 6;
    cout << best(arr1, n1, sum1) << endl; // O(n)

    return 0;
}