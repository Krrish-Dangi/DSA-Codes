#include <iostream>

using namespace std;

void patSearch(string txt, string pat) {
    int n = txt.length();
    int m = pat.length();
    for (int i = 0; i <= n-m;) {
        int j = 0;
        for (j = 0; j < m; j++) {
            if (pat[j] != txt[i+j]) {
                break;
            }
        }
        if (j == m) {
            cout << i << " ";
        }
        if (j == 0) {
            i++; // Naive ki tarah
        }else {
            i = i+j; // Modification
        }
    }
}

int main() {
    string txt = "ABCABCD";
    string pat = "ABCD";
    patSearch(txt, pat);
    return 0;
}