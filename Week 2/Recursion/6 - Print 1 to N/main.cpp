#include <iostream>

using namespace std;

int k{};

void print(int n) {
    if (k == n) {
        return;
    }
    k += 1;
    cout << k << " ";
    print(n);
}

// OR

void print1toN(int n) {
    if (n == 0) {
        return;
    }
    print1toN(n-1);
    cout << n << " ";
}

int main() {
    print(7); // theta(n) and theta(n)
    cout << endl;
    print1toN(7);

    return 0;
}