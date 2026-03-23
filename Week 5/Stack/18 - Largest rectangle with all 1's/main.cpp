#include <iostream>
#include <stack>
using namespace std;

int calculateLargestArea(int arr[], int n) {
    stack<int> s;
    int res = 0;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[i] <= arr[s.top()]) {
            int tp = s.top();
            s.pop();
            int curr = arr[tp] * (s.empty() ? i : i - s.top() - 1);
            res = max(res, curr);
        }
        s.push(i);
    }

    while (!s.empty()) {
        int tp = s.top();
        s.pop();
        int curr = arr[tp] * (s.empty() ? n : n - s.top() - 1);
        res = max(res, curr);
    }
    return res;
}

int LargestRectangle(int arr[][4], int row, int col) {
    int res = calculateLargestArea(arr[0], col);

    for (int i = 1; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] == 1)
                arr[i][j] += arr[i-1][j];
        }

        res = max(res, calculateLargestArea(arr[i], col));
    }
    return res;
}

int main() {
    int arr[][4] = {
        {0,1,1,0},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,0,0}
    };
    int row = 4, col = 4;
    cout << LargestRectangle(arr, row, col) << endl; // theta(rxc) and theta(c)

    return 0;
}
