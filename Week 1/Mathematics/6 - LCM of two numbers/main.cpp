#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0){
        return a;
    }else {
        return gcd(b, a % b);
    }
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {

    // METHOD 1

    // int a,b;
    // cout << "Enter two numbers separated by space: ";
    // cin>>a>>b;
    //
    // int lcm = 1;
    //
    // while (true) {
    //     int gcd1 = gcd(a,b);
    //     lcm = lcm * gcd1;
    //     b = b / gcd1;
    //     a = a / gcd1;
    //     if (gcd1 == 1) {
    //         lcm = lcm * a * b;
    //         break;
    //     }
    // }
    //
    // cout << lcm << endl;

    // METHOD 2

    // int a, b;
    // cout << "Enter two numbers separated by space: ";
    // cin >> a >> b;
    //
    // int result = max(a,b);
    // while (true) {
    //     if (result % a == 0 && result % b == 0) {
    //         cout << result;
    //         break;
    //     }else {
    //         result ++;
    //     }
    // }

    // TIME COMPLEXITY -- O(a*b - max(a,b))

    // METHOD 3 (a*b = gcd*lcm) *BEST*
    cout << lcm(4,6);

    // TIME COMPLEXITY -- theta(log(min(a,b)) and Auxiliary Space: O(log(min(a,b))






    return 0;
}