#include <iostream>
#include <stack>

using namespace std;

void printNextGreaterElement(int *arr, int n) {
    stack<int> s;
    s.push(arr[n-1]);
    cout << -1 << " ";
    for (int i = n-2; i >= 0; i--) {
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
    int arr []= {5,15,10,8,6,12,9,18};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNextGreaterElement(arr, n);

    return 0;
}