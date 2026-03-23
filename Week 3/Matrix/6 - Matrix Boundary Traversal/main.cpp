#include <iostream>
#include <vector>
using namespace std;

void printBoundary(vector<vector<int> > &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Case 1: Only one column
    if (cols == 1) {
        for (int i = 0; i < rows; i++) {
            cout << matrix[i][0] << " ";
        }
    }
    // Case 2: Only one row
    else if (rows == 1) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[0][j] << " ";
        }
    }
    // Case 3: General case
    else {
        // Top row
        for (int j = 0; j < cols; j++) {
            cout << matrix[0][j] << " ";
        }

        // Right column
        for (int i = 1; i < rows; i++) {
            cout << matrix[i][cols - 1] << " ";
        }

        // Bottom row (right to left)
        for (int j = cols - 2; j >= 0; j--) {
            cout << matrix[rows - 1][j] << " ";
        }

        // Left column (bottom to top, excluding first row)
        for (int i = rows - 2; i > 0; i--) {
            cout << matrix[i][0] << " ";
        }
    }
}

int main() {
    vector<vector<int> > matrix{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    printBoundary(matrix); // theta(r*c)
}
