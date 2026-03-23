#include <iostream>
#include <unordered_set>

using namespace std;

void intersection(int arr1[], int arr2[], int m, int n) {
    unordered_set<int> set(arr2,arr2+n);
    for (int i = 0; i < m; i++) {
        if (set.find(arr1[i]) != set.end()) {
            cout << arr1[i] << " ";
        }
    }
}

int main() {
    int arr1[] = {10,20,30};
    int arr2[] = {30,10};
    int len1 = sizeof(arr1) / sizeof(int);
    int len2 = sizeof(arr2) / sizeof(int);
    intersection(arr1, arr2, len1, len2); // theta(m+n) and theta(n)
}