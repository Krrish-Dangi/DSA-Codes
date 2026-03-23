#include <iostream>
#include <math.h>


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


// Method 1 (Naive Solution)
void primeFactor(int n) {
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            int x = i;
            while (n % x == 0) {
                cout << (i) << " ";
                x = x*i;
            }
        }
    }
}

void betterPrimeFactor(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (isPrime(i)) {
            int x = i;
            while (n % x == 0) {
                cout << (i) << " ";
                x = x*i;
            }
        }
    }
}

void bestPrimeFactor(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (isPrime(i)) {
            while (n % i == 0) {
                cout << (i) << " ";
                n = n/i;
            }
        }
    }
    if (n > 1) {
        cout << n;
    }
}

void godPrimeFactor(int n) {
    if (n <= 1) return;
    while(n%2 == 0) {
        cout << 2 << " ";
        n = n/2;
    }
    while(n%3 == 0) {
        cout << 3 << " ";
        n = n/3;
    }
    for (int i = 5; i*i <= n; i += 6) {
        while (n%i == 0) {
            cout << i << " ";
            n = n/i;
        }
        while (n%(i+2) == 0) {
            cout << i+2 << " ";
            n = n/(i+2);
        }
    }
    if (n > 1) {
        cout << n << " ";
    }
}

int main() {

    // Method 1 (Naive Solution)
    primeFactor(450); // TIME COMPLEXITY --> O(nlog(n))
    cout << endl;
    // Method 2 (BETTER)
    betterPrimeFactor(450); // TIME COMPLEXITY --> O(root(n)log(n))
    cout << endl;
    // Method 3 (BEST)
    bestPrimeFactor(450);
    cout << endl;
    // Method 4 (GOD)
    godPrimeFactor(450); // TIME COMPLEXITY --> theta(root(n))

    return 0;
}