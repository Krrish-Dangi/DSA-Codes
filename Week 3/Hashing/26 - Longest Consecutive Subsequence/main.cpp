#include <iostream>
#include <unordered_set>

using namespace std;

int best(int arr[], int n) {
    unordered_set<int> h(arr,arr+n);
    int res = 1;
    for (auto x: h) {
        if (h.find(x-1) == h.end()) {
            int curr = 1;
            while (h.find(x+curr) != h.end()) {
                curr++;
            }
            res = max(res, curr);
        }
    }
    return res;
}

int main() {
    int arr[]{1,3,9,2,8,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << best(arr, n) << endl; // theta(n) and O(n)

    return 0;
}