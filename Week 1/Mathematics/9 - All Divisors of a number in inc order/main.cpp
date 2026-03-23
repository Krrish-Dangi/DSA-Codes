# include <iostream>
#include <math.h>

using namespace std;

void naive(int n) {
    for (int i = 1; i <= n ; i++) {
        if (n%i == 0) {
            cout << i << " ";
        }
    }
}

void better(int n) {
    for (int i = 1; i <= sqrt(n) ; i++) {
        if (n%i == 0) {
            cout << i << " ";
            if ( i != n/i) cout << n/i << " "; // for pairs and eliminating the perfect squares displaying twice
        }
    }
}

void best(int n) {
    int i;
    for (i = 1; i <= sqrt(n) ; i++) { // All divisors  [1 , root n)
        if (n%i == 0) {
            cout << i << " ";
        }
    }
    for (;i >=1; i--){ // All divisors [root n , n]
        if (n%i == 0) {
            cout << n/i << " ";
        }
    }
}

int main() {

    // Method 1 (Naive)
    naive(15); // TIME COMPLEXITY --> theta(n)
    cout << endl;
    // Method 2 (Better)
    better(30); // TIME COMPLEXITY --> theta(root(n))
    cout << endl;
    // Method 3 (Best)
    best(15); // TIME COMPLEXITY --> theta(root(n))
    cout << endl;


    return 0;
}