#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void BucketSort(int arr[], int n, int k) {
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        max_val = max(max_val, arr[i]);
    }

    max_val++;
    vector<vector<int>> bucket(k);
    for (int i = 0; i < n; i++) {
        int bi = (k*arr[i])/max_val;
        bucket[bi].push_back(arr[i]);
    }

    for (int i = 0; i < k; i++) {
        sort(bucket[i].begin(), bucket[i].end());
    }

    int index = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < bucket[i].size(); j++) {
            arr[index++] = bucket[i][j];
        }
    }
}

int main() {
    int arr[]{30,40,10,80,5,12,70};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    BucketSort(arr, n, k);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}