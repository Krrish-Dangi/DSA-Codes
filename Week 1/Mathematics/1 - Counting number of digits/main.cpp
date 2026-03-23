#include <iostream>

using namespace std;

int main() {
    int n{};
    int count{};
    cin >> n;

    while (n>0) {
        n = n/10;
        count++;
    }

    cout << count;

    return 0;
}

// time complexity is theta(no. of digits)