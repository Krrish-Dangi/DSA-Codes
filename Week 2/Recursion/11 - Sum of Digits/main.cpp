#include <iostream>

using namespace std;

int sumDigits(int n) {
    if (n == 0) {
        return 0;
    }

    return n%10 + sumDigits(n/10);
}
// theta(d) and theta(d)

int main() {
    cout << sumDigits(123) << endl;

    return 0;
}