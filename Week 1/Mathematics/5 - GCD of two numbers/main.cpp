// From DMS:- gcd(a,b) = gcd(b,a%b) here a>b

#include <iostream>

using namespace std;

// METHOD 2 (Euclidean Algorithm)
// int gcd(int a, int b) {
//     while (a != b) {
//         if ( a > b) {
//             a = a - b;
//         }else {
//             b = b - a;
//         }
//     }
//     return a;
// }


// METHOD 3 (EUCLIDEAN ALGO MODULO WALA)
int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}


int main() {

    // Method 1 (Naive Solution)

    // int a,b;
    // cout << "Enter two numbers separated by space: ";
    // cin>>a>>b;
    // cout << endl;
    //
    // int result = min(a,b);
    // while (result > 0) {
    //     if (a%result==0 && b%result==0) {
    //         cout << result << endl;
    //         break;
    //     }
    //     result --;
    // }

    // TIME COMPLEXITY --> O(min(a,b))


    // Method 2 (Euclidean Algorithm)

    // cout << gcd(10,15);

    // METHOD 3 (Modulo wala Euclidean Algo) *BEST*

    cout << gcd(15, 5) << endl;

    // TIME COMPLEXITY -- theta(log(min(a,b)) and Auxiliary Space: O(log(min(a,b))
}
