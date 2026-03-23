#include <iostream>

using namespace std;

int main() {

// METHOD 1 (NAIVE SOLUTION)

    // int n{};
    // cout << "Enter a number: ";
    // cin >> n;
    //
    // long long int factorial = 1;
    // for (int i = 1; i <= n; i++) {
    //     factorial *= i;
    // }
    // cout << factorial << endl;
    //
    // int count = 0;
    // int temp = 0;
    // while (factorial > 0) {
    //     temp = factorial % n;
    //     if (temp != 0) {
    //         break;
    //     }else {
    //     if (temp == 0) {
    //         count++;
    //     }
    //     }
    //     factorial /= n;
    // }
    //
    // cout << "Number of trailing zeroes: " << count << endl;

    // TIME COMPLEXITY --> theta (n) but overflow issue

    // METHOD 2 (BEST)

    // Logic 5^(natural numbers) and 2 together makes a 10 , also number of 5 is less than number of 2
    //Since 10 = 2 × 5, and factorials have more 2s than 5s, the number of trailing zeroes depends on how many times 5 is a factor in n!.
    int n{};
    cout << "Enter a number: ";
    cin >> n;

    int res{};
    for (int i = 5; i <= n; i *= 5) {
        res = res + n/i;
    }

    cout << res << endl;

    // TIME COMPLEXITY --> theta(log n) and no overflow issue

    return 0;
}