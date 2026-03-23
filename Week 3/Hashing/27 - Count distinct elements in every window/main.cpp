#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void naive(int arr[], int n, int k) {
    for (int i = 0; i < n-k; i++) {
        int count = 0;
        for (int j = 0; j < k; j++) {
            bool flag = false;
            for (int l = 0; l < j; l++) {
                if (arr[i+j] == arr[i+l]) {
                    flag = true;
                    break;
                }
            }
            if (flag = false) {
                count++;
            }
        }
        cout << count << " ";
    }
}

void countDistinctInWindow(vector<int>& arr, int k) {
    int n = arr.size();
    if (k > n) return;

    unordered_map<int, int> freq;  // element -> frequency

    // Process first window
    for (int i = 0; i < k; i++) {
        freq[arr[i]]++;
    }
    cout << freq.size() << " ";

    // Slide the window
    for (int i = k; i < n; i++) {
        // Remove the element going out of the window
        int out = arr[i - k];
        freq[out]--;
        if (freq[out] == 0) {
            freq.erase(out);
        }

        // Add the new element coming in
        freq[arr[i]]++;

        // Print count of distinct elements
        cout << freq.size() << " ";
    }
}

int main() {
    int arr[]{10,10,5,3,20,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    // naive(arr, n, k); // O((n-k)*k*k
    vector<int> arr2{10,10,5,3,20,5};
    countDistinctInWindow(arr2, k); //  O(n) and O(n)
}