#include <algorithm>
#include <iostream>

using namespace std;

void Naive(int arr1[], int m, int arr2[], int n) {
    int c[m+n];
    for (int i = 0; i < m; i++) {
        c[i] = arr1[i];
    }
    for (int i = 0; i < n; i++) {
        c[m+i] = arr2[i];
    }
    sort(c, c+m+n);
    for (int i = 0; i < m+n; i++) {
        cout << c[i] << " ";
    }
}

void best(int arr1[], int m, int arr2[], int n) {
    int i{0},j{0};
    while (i < m && j < n) {
        if (arr1[i] <= arr2[j]) { // <= is for stability
            cout << arr1[i] << " ";
            i++;
        }else {
            cout << arr2[j] << " ";
            j++;
        }
    }
    while (i < m) {
        cout << arr1[i] << " ";
        i++;
    }
    while (j < n) {
        cout << arr2[j] << " ";
        j++;
    }
}


int main() {
    int arr1[] = {10,15,20,20};
    int arr2[] = {1,12};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    Naive(arr1, n1, arr2, n2); // O((m+n)log(m+n)) and O(m+n)

    cout << endl;

    int arr3[] = {10,15,20,20};
    int arr4[] = {1,12};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    int n4 = sizeof(arr4)/sizeof(arr4[0]);
    Naive(arr3, n3, arr4, n4); // theta(m+n) and O(1)
}