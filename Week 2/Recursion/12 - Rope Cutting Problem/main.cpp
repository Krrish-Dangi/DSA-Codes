#include <iostream>

using namespace std;

int max(int x, int y, int z) {
    if (x > y && x > z) {
        return x;
    }
    else if (y > x && y > z) {
        return y;
    }
    else if (z > x && z > y) {
        return z;
    }else {
        return 0;
    }
}

int compute(int n, int a, int b, int c) {
    if (n==0) return 0;
    if (n < 0) return -1;
    int res = max(compute(n-a, a, b, c), compute(n-b, a, b, c),compute(n-c,a,b,c));

    if (res == -1) {
        return -1;
    }
     return res+1;
}

int main() {
    cout << compute(23,11,9,12); // Time complexity --> O(3**n)

    return 0;
}