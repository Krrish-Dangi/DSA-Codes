// given a number n:- find all the prime numbers less than equal to n
#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {
    bool isPrime = true;
    if (n == 1) return false;
    else if (n == 2 || n == 3) {
        return true;
    }else if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }else{
        for (int i = 5; i*i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                isPrime = false;
                break;
            }
        }
    }

    if (isPrime) {
        return true;
    }

    return false;
}

void naive(int n) {
    for (int i = 2; i <=n ; i ++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
}

void best(int n) {
    vector <bool> v(n+1,true);
    for (int i = 2; i*i <= n ; i ++) {
        if (v[i]) {
            for (int j = 2*i; j <= n; j += i) {
                v[j] = false;
            }
        }
    }

    for (int i = 2; i <= n ; i ++) {
        if (v[i]) {
           cout << i << " ";
        }
    }
}

void god(int n) {
    vector <bool> v(n+1,true);
    for (int i = 2; i*i <= n ; i ++) {
        if (v[i]) {
            for (int j = i*i; j <= n; j += i) { // **
                v[j] = false;
            }
        }
    }

    for (int i = 2; i <= n ; i ++) {
        if (v[i]) {
            cout << i << " ";
        }
    }
}


int main() {
    // Method 1 (Naive)
    naive(23); // TIME COMPLEXITY --> O(n*root(n))
    cout << endl;

    // Method 2 (BEST Sieve of Eratosthenes algorithm)
    best(23);
    cout << endl;

    // Method 3 (GOD Sieve of Eratosthenes algorithm)
    best(23); // TIME COMPLEXITY --> O(nloglogn)
    cout << endl;


    return 0;
}