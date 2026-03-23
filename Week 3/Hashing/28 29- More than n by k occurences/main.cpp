#include <iostream>
#include <unordered_map>

using namespace std;

void hashMethod(int arr[], int n, double k) {
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    double req = n/k;

    for (auto elem: hash ) {
        if (elem.second >= req) {
            cout << elem.first << " ";
        }
    }
}

void best(int arr[], int n, int k) {
    if (k < 2) return;

    // Step 1: Find potential candidates
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        int x = arr[i];

        if (freq.find(x) != freq.end()) {
            freq[x]++;
        }

        else if (freq.size() < k - 1) {
            freq[x] = 1;
        }
        else {
            // decrease count of all candidates
            for (auto it = freq.begin(); it != freq.end();) {
                it->second--;
                if (it->second == 0) {
                    it = freq.erase(it);
                } else {
                    ++it;
                }
            }
        }
    }

    // Step 2: Verify candidates
    unordered_map<int, int> actual;
    for (int i = 0; i < n; i++) {
        if (freq.find(arr[i]) != freq.end()) {
            actual[arr[i]]++;
        }
    }

    for (auto& it : actual) {
        if (it.second > n / k) {
            cout << it.first << " ";
        }
    }
    cout << "\n";
}

int main() {
    int arr[]{10,10,20,30,20,10,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    hashMethod(arr, n, 2); // theta(n) and theta(n/k)
    best(arr, n, 2); // theta(n*k) and theta(k-1)
}