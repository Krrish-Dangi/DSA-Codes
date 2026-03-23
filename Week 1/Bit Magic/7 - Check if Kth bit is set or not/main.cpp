#include <iostream>

using namespace std;

bool checkKthBit(int n, int k) {
    int bit{};
    int kth{1};
    while (n > 0 && kth == k) {
        bit = n & 1;
        if (bit == 1 && kth == k) {
            return true;
        }
        n = n / 10; // OR n = n >> 1 (BEST)
        kth++;
    }
    return false;
}

void Best(int n, int k) // theta (1)
{
    if ((n >> (k - 1)) & 1)
        cout << "SET";
    else
        cout << "NOT SET";
}


int main() {

    if (checkKthBit(1, 1)) { // TIME COMPLEXITY --> theta(k)
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;

    }

    Best(1, 4);



    return 0;
}