#include <iostream>

using namespace std;

int k{0};
void sumOfNaturalNumbers(int n) {
    if (n == 0) {
        cout << (k) << endl;
        return;
    }
    k += n;
    sumOfNaturalNumbers(n-1);
}

int main() {
    sumOfNaturalNumbers(10);


    return 0;
}