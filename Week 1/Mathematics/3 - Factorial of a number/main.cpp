#include <iostream>

using namespace std;

// METHOD 2

int fac(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }else {
        return n * fac(n - 1);
    }
}

int main() {

    // METHOD 1 (BEST)

    // int n{};
    // cout << "Enter a number: ";
    // cin >> n;
    //
    // int factorial = 1;
    // for (int i = 1; i <=n ; i++) {
    //     factorial *= i;
    // }
    //
    // cout << factorial;

    // TIME COMPLEXITY --> theta(n)

    // METHOD 2
    int n{};
    cout << "Enter a number: ";
    cin >> n;

    cout << fac(n) << endl;

    // TIME COMPLEXITY --> theta(n) but AUXILIARY SPACE --> theta(n)

}