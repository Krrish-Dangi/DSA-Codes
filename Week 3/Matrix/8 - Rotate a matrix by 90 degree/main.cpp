#include <iostream>
#include <vector>

using namespace std;

void Transpose(vector<vector<int> > &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = i+1; j < matrix.size(); j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

// Transpose --> Reverse individual columns
void rotateby90(vector<vector<int> > &matrix) {
    Transpose(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        int low = 0, high = matrix.size()-1;
        while (low <= high) {
            swap(matrix[low][i], matrix[high][i]);
            low++;
            high--;
        }
    }
}

int main() {
    vector<vector<int> > matrix{{1,2,3},{4,5,6},{7,8,9}};
    rotateby90(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}