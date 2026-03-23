#include <iostream>

using namespace std;

int squareRoot(int n) {
    int low = 0;
    int high = n;
    int ans = -1;
    while (low <= high) {
        int mid = (low + high)/2;
        int sqmid = mid*mid;
        if (sqmid == n) {
            ans = mid;
        }else if (sqmid > n) {
            high = mid - 1;
        }else {
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}

int main() {
    cout << squareRoot(10) << endl;
}