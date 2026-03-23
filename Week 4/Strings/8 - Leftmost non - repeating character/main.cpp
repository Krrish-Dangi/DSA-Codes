#include <iostream>

using namespace std;

char count(string s) {
   int count[256]{0};
    for (int i = 0; i < s.length(); i++) {
        count[s[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] == 1) {
            return char(i);
        }
    }
}

int main() {
    string s{"abbcda"};
    cout << count(s) << endl; // O(n)

    return 0;
}