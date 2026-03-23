#include <iostream>
#include <stack>

using namespace std;

void printPreviousGreaterElement(int *arr, int n) {
    stack<int> s;
    s.push(arr[0]);
    cout << -1 << " ";
    for (int i = 1; i < n; i++) {
        while (s.empty() == false && s.top() <= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            cout << -1 << " ";
        }else {
            cout << s.top() << " ";
        }
        s.push(arr[i]);
    }
}

int main() {
    int arr []= {15,10,18,12,4,6,2,8};
    int n = sizeof(arr) / sizeof(arr[0]);
    printPreviousGreaterElement(arr, n);

    return 0;
}