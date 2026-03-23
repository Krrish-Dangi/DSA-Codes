#include <iostream>
#include <unordered_set>

using namespace std;

bool isPair(int arr[], int n, int sum) {
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        if (s.find(sum - arr[i]) != s.end()) {
            return true;
        }else {
            s.insert(arr[i]);
        }
    }
    return false;
}

int main() {
    int arr[]{1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << boolalpha;
    cout << isPair(arr, n, 5) << endl;
    return 0;
}