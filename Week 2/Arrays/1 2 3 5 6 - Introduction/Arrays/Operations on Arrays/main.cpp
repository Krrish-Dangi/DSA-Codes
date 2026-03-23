#include <iostream>

using namespace std;

int main() {
    // 1. Searching
    int arr[10]{1,2,3,4,5};
    int x{2};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) { // O(n)
        if (x == arr[i]) {
            cout << i << endl;
        }
    }

    // 2. Inserting in any index
    int position = 3;
    int elem = 69;
    cout << arr[position-1] << endl;
    for (int i = n -1; i >= position-1; i--) { // O(n)
        arr[i+1] = arr[i];
    }
    arr[position-1] = elem;
    cout << "-------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    // 3. Delete an element
    int array[10]{1,2,3,4,5};
    int element = 6;
    int index{};
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (array[i] == element) {
            index = i;
            flag = false;
            break;
        }
    }

    if (index == 0 && flag) {
        index = sizeof(arr) / sizeof(arr[0]);
    }

    for (int i = index + 1; i < n; i++) {
        array[i-1] = array[i];
    }

    cout << "---------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }

}