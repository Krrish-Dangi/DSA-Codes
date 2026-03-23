#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool isPalindrome(string s, int n) {
    if (n == s.length()/2) {
        return true;
    }
    if (s[s.length() - 1 - n] != s[n]) {
        return false;
    }
    n += 1;
    return isPalindrome(s, n); // Tail Recursive
}
// O(n) and O(n)

int main() {
    cout << boolalpha;
    cout << isPalindrome("geek", 0);

    return 0;
}