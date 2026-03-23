#include <iostream>
#include <vector>
using namespace std;

int naive(string s, int n) {
    for (int len = n-1; len > 0; len--) {
        bool flag = true;
        for (int i = 0; i < len; i++) {
            if (s[i] != s[n-len+i]) {
                flag = false;
                break;
            }
        }
        if (flag) return len;
    }
    return 0;
}

void fillLPS(string s, vector<int>& lps) {
    for (int i = 0; i < s.length(); i++) {
        lps[i] = naive(s, i+1);
    }
}

void best(string s, vector<int>& lps) {
    int n = s.length();
    int len = 0;
    int i = 1;
    while (i < n) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        }else {
            if (len == 0) {
                lps[i] = 0;
                i++;
            }else {
                len = lps[len-1];
            }
        }
    }
}

int main() {
    string s{"ababacab"};
    vector<int> lps(s.length());
    // fillLPS(s, lps); // O(n**3)
    best(s, lps); // theta(n)
    for (int i = 0; i < lps.size(); i++) {
        cout << lps[i] << endl;
    }

    return 0;
}
