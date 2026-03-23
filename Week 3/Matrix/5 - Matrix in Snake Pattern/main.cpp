#include <iostream>
#include <vector>

using namespace std;

void printSnakePattern(vector<vector<int>> snake) {
    for (int i = 0; i < snake.size(); i++) {
        if (i%2 != 0) {
            for (int j = snake[i].size()-1; j >= 0; j--) {
                cout << snake[i][j] << " ";
            }
        }else {
            for (int j = 0; j < snake[i].size(); j++) {
                cout << snake[i][j] << " ";
            }
        }
    }
}

int main() {
    vector<vector<int>> snake{{1,2,3,4},
                              {5,6,7,8},
                              {9,10,11,12},
                              {13,14,15,16}};
    printSnakePattern(snake); // theta(n**2)
}
