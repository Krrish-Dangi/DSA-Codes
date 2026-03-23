#include <iostream>
#include <unordered_set>

using namespace std;

bool is0Subarray(int arr[], int n) {
    unordered_set<int> s;
    int pre_sum = 0;
    for (int i = 0; i < n; i++) {
        pre_sum += arr[i];
        if (s.find(pre_sum) != s.end()) {
            return true;
        }
        if (pre_sum == 0) {
            return true;
        }
        s.insert(pre_sum);
    }
    return false;
}

int main() {
    int arr[]{-3,4,-3,-1,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << boolalpha;
    cout << is0Subarray(arr, n) << endl; // O(n)
}