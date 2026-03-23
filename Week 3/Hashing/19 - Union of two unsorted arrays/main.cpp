#include <iostream>
#include <unordered_set>

using namespace std;

int Union(int a[], int m, int b[], int n){
    unordered_set<int> s1(a,a+m);
    for (int i = 0; i < n; i++) {
        s1.insert(b[i]);
    }
    return s1.size();
}

int main() {
    int arr1[]{15,20,5,15};
    int arr2[]{15,15,15,20,10};
    int len1 = sizeof(arr1)/sizeof(int);
    int len2 = sizeof(arr2)/sizeof(int);
    cout << Union(arr1, len1, arr2, len2) << endl; // theta(m+n) and O(m+n)
    return 0;
}