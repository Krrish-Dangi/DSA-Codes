#include <iostream>

using namespace std;

int arr[]{2,8,3,9,6,5,4};
int n= sizeof(arr)/sizeof(arr[0]);
int ps[n];

void preProcess() {
    ps[0] = arr[0];
    for (int i = 1; i < n; i++) {
        ps[i] = ps[i-1] + arr[i];
    }
}

int naive(int l, int r){
    int sum=0;
    for (int i = l; i <= r ; i++) {
        sum += arr[i];
    }
    return sum;
}

int best(int l, int r) {
    preProcess();
    if (l == 0) {
        return ps[r];
    }else {
        return ps[r] - ps[l-r];
    }
}

int main() {
    // cout << naive(1,3) << endl; // theta(r-l+1) or theta(n)
    cout << best(1,3) << endl; // theta(1)
}