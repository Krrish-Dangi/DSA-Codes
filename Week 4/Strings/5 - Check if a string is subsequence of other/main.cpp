#include <iostream>

using namespace std;

bool best(string s, string sub) {
    if (sub.length() > s.length()) {
        return false;
    }
    int i = 0, j = 0;
    while (i < s.size() && j < sub.size()) {
        if (s[i] == sub[j]) {
            i++;
            j++;
        }else {
            i++;
        }
    }
    return j == sub.size();
}

int main() {
    string s1 = "ABCD";
    string s2 = "AD";
    cout << boolalpha;
    cout << best(s1, s2) << endl; // theta(n)

    string s3 = "ADC";
    cout << best(s1, s3) << endl;
    return 0;
}