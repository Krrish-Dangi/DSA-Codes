// Print count of every letter in sorted order

#include <iostream>
#include <string>

using namespace std;

void print(string s) {
    int count[26]{0};
    for (int i = 0; i < s.length(); i++) {
        count[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            cout << (char)(i+'a') << " " << count[i] << endl;
        }
    }
}

int main() {
    print("geeksforgeeks");
}