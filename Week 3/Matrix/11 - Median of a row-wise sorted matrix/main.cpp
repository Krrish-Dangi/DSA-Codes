#include <algorithm>
#include <iostream>
using namespace std;

int matMed(int mat[][5], int r, int c) {
    int mn = mat[0][0], mx = mat[0][c - 1];
    for (int i = 1; i < r; i++) {
        if (mat[i][0] < mn) mn = mat[i][0];
        if (mat[i][c - 1] > mx) mx = mat[i][c - 1];
    }

    int desired = (r * c + 1) / 2;
    while (mn < mx) {
        int mid = mn + (mx - mn) / 2;
        int place = 0;

        for (int i = 0; i < r; i++) {
            place += upper_bound(mat[i], mat[i] + c, mid) - mat[i];
        }

        if (place < desired)
            mn = mid + 1;
        else
            mx = mid;
    }
    return mn;
}

int main() {
    int mat[3][5] = {
        {5, 10, 20, 30, 40},
        {1, 2, 3, 4, 6},
        {11, 13, 15, 17, 19}
    };
    cout << "Median is " << matMed(mat, 3, 5) << endl; // theta(r*log((mx-mn))*log(c))
    return 0;
}
