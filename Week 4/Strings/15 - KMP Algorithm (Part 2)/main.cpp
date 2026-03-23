#include <iostream>
using namespace std;

void fillLPS(string s, int lps[]) {
    int n = s.length();
    lps[0] = 0;
    int len = 0;
    int i = 1;

    while (i < n) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(string txt, string pat) {
    int n = txt.length();
    int m = pat.length();
    int lps[m];

    fillLPS(pat, lps);

    int i = 0, j = 0;
    while (i < n) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }
        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pat[j] != txt[i]) {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
}

int main() {
    string txt = "ababcababaad";
    string pat = "ababa";
    KMP(txt, pat); // O(n) and theta(m)
    return 0;
}
