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

int main() {
    vector<vector<int> > matrix{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    Transpose(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}