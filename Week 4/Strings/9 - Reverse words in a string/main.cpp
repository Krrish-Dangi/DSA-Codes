#include <iostream>

using namespace std;

void reverseString(string &s, int start, int end) {
    while (start <= end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

void ReverseWords(string &s) {
    int start = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            reverseString(s, start, i - 1); // reverse current word
            start = i + 1;
        }
    }
    // Reverse the last word
    reverseString(s, start, s.length() - 1);

    // Reverse the entire string
    reverseString(s, 0, s.length() - 1);
}

int main() {
    string s = "hello world";
    ReverseWords(s);
    cout << s << endl; // Output: "world hello"
    return 0;
}
