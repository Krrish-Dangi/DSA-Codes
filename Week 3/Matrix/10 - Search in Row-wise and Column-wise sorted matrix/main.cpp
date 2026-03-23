#include <iostream>
#include <vector>

using namespace std;

// Top right ya bottom left se chalu kro
void search(vector<vector<int> > matrix, int x) {
    int i = 0, j = matrix[0].size() - 1;
    while (i < matrix.size() && j >=0) {
        if (matrix[i][j] == x) {
            cout << "Found at: " << i << " " << j << endl;
            return;
        }else if (matrix[i][j] > x) {
            j--;
        }else {
            i++;
        }
    }
    cout << "Not Found!" << endl;
    return;
}

int main() {
    vector<vector<int>> matrix{{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
    int x = 24;
    search(matrix,x); // theta(r+c)
}