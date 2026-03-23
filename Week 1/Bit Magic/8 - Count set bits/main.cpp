#include <iostream>

using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        if (n % 2 == 1 ) { // OR n & 1
            count++;
        }
        n = n / 2; // OR n >> 1
    }
    return count;
}

int BrianKerningamAlgorithm(int n) {
    int result = 0;
    while (n > 0) {
        n = n & (n - 1); // When we sub by 1, all the trailing zeroes becomes 1 and last 1 of n becomes 0
        result ++;
    }
    return result;
}

int tbl[256];

void initalize() { // PREPROCESSING
    tbl[0] = 0;
    for (int i = 1; i < 256; i++) {
        tbl[i] = tbl[i & i-1] + 1;
    }
}

int Best(int n) {
    return tbl[n & 255] + tbl[(n >> 8) & 255] + tbl[(n >> 16) & 255] + tbl[(n >> 24) & 255];

}

int main() {
    cout << countSetBits(13) << endl; // TIME COMPLEXITY --> theta(no. of bits)
    cout << BrianKerningamAlgorithm(13) << endl; // TIME COMPLEXITY --> theta(no. of set bits) *BETTER*
    cout << Best(13) << endl; // TIME COMPLEXITY --> O(1)

    return 0;
}
