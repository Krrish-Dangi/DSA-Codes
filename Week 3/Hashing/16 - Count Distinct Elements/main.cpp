#include <iostream>
#include <unordered_set>

using namespace std;

int countDistinctElements(int arr[], int n) {
    // unordered_set<int> s;
    // for (int i = 0; i < n; i++) {
    //     s.insert(arr[i]);
    // }
    // return s.size();

    // OR

    unordered_set<int>s(arr,arr+n);
    return s.size();
}

int main() {
    int arr[]{10,20,20,30,40};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << countDistinctElements(arr, n) << endl; // theta(n) and theta(n)
}