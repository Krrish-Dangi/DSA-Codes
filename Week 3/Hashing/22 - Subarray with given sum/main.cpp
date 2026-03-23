#include <iostream>
#include <unordered_set>

using namespace std;

bool check(int arr[], int n, int sum) {
    unordered_set<int> s;
    int pre_sum = 0;
    for (int i = 0; i < n; i++) {
        pre_sum += arr[i];
        if (pre_sum == sum) {
            return true;
        }
        if (s.find(pre_sum) != s.end()) {
            return true;
        }
        s.insert(pre_sum);
    }
    return false;
}

int main() {
    int arr[]{5,3,2,-1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 4;
    cout << boolalpha;
    cout << check(arr, n, sum); // O(n)
}