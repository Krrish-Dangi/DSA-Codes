// Minimize the maximum pages allocated
// Only contiguous pages can be allocated

#include <iostream>

using namespace std;

int sum(int arr[], int n, int k);
bool isFeasible(int arr[], int n, int k, int ans);

int naive(int arr[], int n, int k) {
    if (k == 1) return sum(arr,0,n-1);
    if (n == 1) return arr[0];
    int res = INT_MAX;
    for (int i = 1; i < n; i++) {
        res = min(res, max(naive(arr,i,k-1),sum(arr,i,n-1)));
    }
    return res;
}

int sum(int arr[], int b, int k) {
    int s = 0;
    for (int i = b; i <= k; i++) {
        s += arr[i];
    }
    return s;
}

int best(int arr[], int n, int k) {
    int sum = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        mx = max(mx,arr[i]);
    }

    int high = sum, low = mx, res = 0;
    while (low <= high) {
        int mid = (low+high)/2;
        if (isFeasible(arr,n,k,mid)) {
            res = mid;
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    return res;
}

bool isFeasible(int arr[], int n, int k, int ans) {
    int req = 1, sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + arr[i] > ans) {
            req++;
            sum = sum + arr[i];
        }else {
            sum += arr[i];
        }
    }
    return req <= k;
}

int main() {
    int arr[]{10,20,30,40};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << naive(arr,n,2) << endl;

    int arr1[]{10,20,30,40};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << best(arr1,n1,2) << endl; // O(nlog(sum-mx))
}