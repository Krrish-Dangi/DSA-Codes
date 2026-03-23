#include <iostream>

using namespace std;

int naive(int left[], int right[], int n) {
    int freq[100]{0};
    for (int i = 0; i < n; i++) {
        for (int j = left[i]; j <= right[i]; j++) {
            freq[j]++;
        }
    }
    int res = 0;
    for (int i = 0; i < 100; i++) {
        if (freq[i] > freq[res]) {
            res = i;
        }
    }
    return res;
}

int best(int left[], int right[], int n) {
    int freq[101]{0};
    for (int i = 0; i < n; i++) {
        freq[left[i]]++;
        freq[right[i]+1]--;
    }

    int res = 0;
    for (int i = 0; i < 100; i++) {
        freq[i] = freq[i-1] + freq[i];
        if (freq[i] > freq[res]) {
            res = i;
        }
    }
    return res;
}

int main() {
    int left[]{1,2,4};
    int right[]{4,5,7};
    cout << naive(left, right, 3) << endl; // O(n*MAX) here MAX = 100

    int left1[]{1,2,4};
    int right1[]{4,5,7};
    cout << best(left1, right1, 3) << endl; // O(n)
}