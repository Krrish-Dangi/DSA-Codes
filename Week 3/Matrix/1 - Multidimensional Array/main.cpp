#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Other ways to create:

    // 1. Double Pointer
    int m = 3, n = 2;
    int **arr; // Allocated in heap, Jagged Array is possible
    arr = new int*[m];
    for (int i = 0; i < m; i++) {
        arr[i] = new int[n];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 10;
            cout << arr[i][j] << " ";
        }
    }

    cout << endl;

    // 2. Array of pointer
    int *arr1[m];
    for (int i = 0; i < m; i++) {
        arr1[i] = new int[n];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr1[i][j] = 10;
            cout << arr1[i][j] << " ";
        }
    }

    cout << endl;

    // 3. Array of vectors
    vector<int> arr2[m];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr2[i].push_back(10);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr2[i][j] << " ";
        }
    }

    cout << endl;

    // 4. Vector of Vectors (best)
    vector<vector<int>> arr3;
    for (int i = 0; i < m; i++) {
        vector<int> arr4;
        for (int j = 0; j < n; j++) {
            arr4.push_back(10);
        }
        arr3.push_back(arr4);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr3[i][j] << " ";
        }
    }
}