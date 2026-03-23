#include <iostream>
#include <stack>
using namespace std;

int calculateLargestArea(int arr[], int n) {
    stack<int> s;
    int res = 0;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[i] <= arr[s.top()]) {
            int tp = s.top();
            s.pop();
            int curr = arr[tp] * (s.empty() ? i : i - s.top() - 1);
            res = max(res, curr);
        }
        s.push(i);
    }

    while (!s.empty()) {
        int tp = s.top();
        s.pop();
        int curr = arr[tp] * (s.empty() ? n : n - s.top() - 1);
        res = max(res, curr);
    }
    return res;
}

int main() {
    int arr[] = {6,2,5,4,1,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << calculateLargestArea(arr, n) << endl; // Output: 12
    return 0;
}
