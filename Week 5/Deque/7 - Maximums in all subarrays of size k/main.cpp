#include <iostream>
#include <deque>

using namespace std;

void print(int arr[], int n, int k) {
    deque<int> q;
    for (int i = 0; i < n; i++) {
        while (!q.empty() && arr[i] >= arr[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }

    for (int i = k; i < n; i++) {
        cout << arr[q.front()] << " ";
        while (!q.empty() && q.front() <= i - k) {
            q.pop_front();
        }
        while (!q.empty() && arr[i] >= arr[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    cout << arr[q.front()] << " ";
}

int main() {
    int arr[]{10,8,5,12,15,7,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n,3); // O(n)
    return 0;
}