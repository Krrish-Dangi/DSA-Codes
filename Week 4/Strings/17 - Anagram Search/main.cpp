#include <iostream>
using namespace std;

// Helper: check if two frequency arrays are the same
bool areSame(int a[], int b[]) {
    for (int i = 0; i < 256; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

bool isAnagram(string s, string t, int i) {
    int count[256] = {0};
    int m = t.length();

    for (int j = 0; j < m; j++) {
        count[t[j]]++;       // pattern
        count[s[i + j]]--;   // substring of text
    }

    // Check if all counts are zero
    for (int j = 0; j < 256; j++) {
        if (count[j] != 0) return false;
    }
    return true;
}

// Naive: O((n-m+1)*m)
bool naive(string txt, string pat) {
    int n = txt.length();
    int m = pat.length();
    for (int i = 0; i <= n - m; i++) {
        if (isAnagram(txt, pat, i)) {
            return true;  // at least one match found
        }
    }
    return false;
}

// Optimized: O(n*256) ~ O(n)
bool best(string txt, string pat) {
    int n = txt.length();
    int m = pat.length();

    if (m > n) return false;

    int CT[256] = {0};  // frequency in current window
    int CP[256] = {0};  // frequency of pattern

    // First window
    for (int i = 0; i < m; i++) {
        CT[txt[i]]++;
        CP[pat[i]]++;
    }

    // Slide the window
    for (int i = m; i < n; i++) {
        if (areSame(CT, CP)) return true;

        CT[txt[i]]++;          // include new char
        CT[txt[i - m]]--;      // remove old char
    }

    // Check last window
    return areSame(CT, CP);
}

int main() {
    string s = "geeksforgeeks";
    string t = "eeks";
    cout << "Naive: " << naive(s, t) << endl; // O((n-m+1)*m)
    cout << "Best : " << best(s, t) << endl;  // O(n*256)
    return 0;
}
