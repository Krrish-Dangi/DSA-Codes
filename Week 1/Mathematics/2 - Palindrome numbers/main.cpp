#include <iostream>
#include <vector>

using namespace std;

int main() {

    // METHOD 1

//     int n{};
//     cout << "Enter a number: ";
//     cin >> n;
//     int original = n;
//     vector<int> reversed;
//     while (n > 0) {
//         reversed.push_back(n % 10);
//         n /= 10;
//     }
//
//     bool flag = true;
//     for (int i = 0; i < reversed.size(); i++) {
//         if (reversed[i] != reversed[reversed.size() - i - 1]) {
//             cout << "Not a Palindrome" << endl;
//             flag = false;
//             break;
//         }
//     }
//
// if (flag) {
//     cout << "Number is a Palindrome" << endl;
// }

// TIME COMPLEXITY OF METHOD 1 --> theta(number of digits) but AUXILIARY SPACE IS theta(no. of digits)

    // METHOD 2 (BEST)

    int n{};
    cout << "Enter a number: ";
    cin >> n;

    int copy = n;

    int rev{};
    while (n > 0) {
        rev = rev*10 + n%10;
        n = n/10;
    }

    if (copy == rev) {
        cout << "Your number is palindrome";
    }else {
        cout << "Your number is not palindrome";
    }

    return 0;
}

// TIME COMPLEXITY FOR METHOD 2 --> theta(no. of digits)