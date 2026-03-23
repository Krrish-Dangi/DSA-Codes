// If the caller has nothing to do after calling then it is called tail recursion which takes less time and less auxiliary space than normal recursion

#include <iostream>

using namespace std;

int k{};

void print(int n) {
    if (k == n) {
        return;
    }
    k += 1;
    cout << k << " ";
    print(n); // Tail Recursive
}

int fac(int n) {
    if (n == 0) {
        return 1;
    }
    return n*fac(n-1); // Not Tail Recursive
}

int res{1};
void TailFac(int n) {
    if (n == 0) {
        cout << res << endl;
        return;
    }
    res *= n;
    TailFac(n-1); // Tail Recursive
}

int main() {
    print(5);
    cout << endl;
    cout << fac(5);
    cout << endl;
    TailFac(5);

    return 0;
}