#include <iostream>

using namespace std;

int print(int n) {
    if (n == 1) {
        return 1;
    }

    cout << n << " "  << print(n-1) << endl;
}

int main() {
    print(7); // theta(n) and theta(n)


    return 0;
}