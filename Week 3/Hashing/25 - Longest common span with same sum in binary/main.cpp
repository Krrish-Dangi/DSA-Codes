#include <iostream>
#include <unordered_map>

using namespace std;

int check(int arr[], int n, int sum) {
    unordered_map<int, int> m;
    int pre_sum = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        pre_sum += arr[i];
        if (pre_sum == sum) {
            res = i+1;
        }

        if (m.find(pre_sum) == m.end()) {
            m.insert({pre_sum, i});
        }
        if (m.find(pre_sum - sum) != m.end()) {
            res = max(res, i - m[pre_sum - sum]);
        }
    }
    return res;
}

int max(int arr1[], int arr2[], int n) {
    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = arr1[i] - arr2[i];
    }

    return check(temp,n,0);
}

int main() {
    int arr1[]{0,1,0,0,0,0};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[]{0,1,0,0,0,0};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    cout << max(arr1, arr2, n1) << endl;

    return 0;
}
