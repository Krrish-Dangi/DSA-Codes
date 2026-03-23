#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int,int> freq(int arr[], int n) {
    unordered_map<int,int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    return freq;
}

int main() {
    int arr[]{10,20,20,10,30,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    unordered_map<int,int> result = freq(arr, n); // theta(n) and theta(no. of distinct elem)
    for (auto elem: result) {
        cout << elem.first << " " << elem.second << endl;
    }
    return 0;
}