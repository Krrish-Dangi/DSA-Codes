#include <iostream>
#include <string>
#include <iomanip>

// Naive --> reverse kr k check krlo (T.C:- theta(n) and A.S:- theta(n))

using namespace std;

bool isPalindrome(string s) {
    for (int i = 0; i < s.length()/2; i++) {
        if (s[i] != s[s.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s{"geeksforgeeks"};
    cout << boolalpha;
    cout << isPalindrome(s) << endl; // O(n)

    string s1 = "naman";
    cout << isPalindrome(s1) << endl;

    return 0;
}