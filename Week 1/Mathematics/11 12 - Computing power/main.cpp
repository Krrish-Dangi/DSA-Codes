#include <iostream>

using namespace std;

long int power(int base, int exp) {
    long int result = 1;
    for (int i = 1; i <= exp; i++) {
        result = result * base;
    }
    return result;
}

long int better(int base, int exp) {
    if (exp % 2 == 0) {
        long int x = power(base,exp/2);
        return x * x;
    }else {
        return power(base, exp-1)*base;
    }
}

long int best(int base, int exp) {
    long int result = 1;
    while (exp > 0) {
        if (exp%2 != 0) { // OR (n & 1)
            result = result * base;
        }
        base = base * base;
        exp = exp/2; // LSB htao  // OR (n >> 1)
    }
        return result;
}

int main(){
    // METHOD 1 (Naive Solution)
    cout << power(3,4) << endl; // TIME COMPLEXITY --> O(exp)

    // METHOD 2 (BETTER)
    cout << better(3,4) << endl; // TIME COMPLIEXITY AND AUXILIARY SPACE--> O(log n)

    // METHOD 3 (BEST) *ITERATIVE POWER*
    cout << best(3,4) << endl; // TIME COMPLEXITY --> O(log n) and AUXILIARY SPACE --> O(1)


return 0;
}