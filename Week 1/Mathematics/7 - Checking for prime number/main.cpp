#include <iostream>

using namespace std;

int main() {
    // METHOD 1 (Naive Method)
    // int n;
    // cout << "Enter a number: ";
    // cin>>n;
    // cout << endl;
    // if (n == 1) {
    //     cout << "Neither Composite nor prime" << endl;
    // }else {
    //     int flag = true;
    //     for (int i = 2; i < n; i++) {
    //         if (n % i == 0) {
    //             cout << "composite" << endl;
    //             flag = false;
    //             break;
    //         }
    //     }
    //     if (flag) {
    //         cout << "prime" << endl;
    //     }
    // }
    // TIME COMPLEXITY -- O(n)

    // METHOD 2 (BETTER)
    // int n;
    // cout << "Enter a number: ";
    // cin>>n;
    // cout << endl;
    // if (n == 1) {
    //     cout << "Neither Composite nor prime" << endl;
    // }else {
    //     bool isPrime = true;
    //     for (int i = 2; i*i <= n; i++) {
    //         if (n % i == 0) {
    //             cout << "composite" << endl;
    //             isPrime = false;
    //             break;
    //         }
    //     }
    // if (isPrime) {
    //     cout << "prime" << endl;
    // }
    // }

    // METHOD 3 (BEST)
    int n;
    cout << "Enter a number: ";
    cin>>n;
    cout << endl;

    bool isPrime = true;
    if (n == 1) cout << "Neither prime nor composite" << endl;
    else if (n == 2 || n == 3) {
        cout << "Prime" << endl;
    }else if (n % 2 == 0 || n % 3 == 0) {
        cout << "Composite" << endl;
        isPrime = false;
    }else{
        for (int i = 5; i*i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                cout << "Composite" << endl;
                isPrime = false;
                break;
            }
        }
    }

    if (isPrime) {
        cout << "Prime" << endl;
    }



    return 0;
}

