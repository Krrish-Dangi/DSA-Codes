#include <iostream>
using namespace std;

void RBSearch(string pat, string txt) {
    int m = pat.length();
    int n = txt.length();
    int d = 256; // number of characters
    int q = 101; // prime number

    int h = 1;
    for (int i = 0; i < m-1; i++) {
        h = (h * d) % q;
    }

    int p = 0, t = 0;
    for (int i = 0; i < m; i++) {
        p = (p * d + pat[i]) % q;
        t = (t * d + txt[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            bool flag = true;
            for (int j = 0; j < m; j++) {
                if (txt[i + j] != pat[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) cout << i << " ";
        }

        if (i < n - m) {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;
            if (t < 0) t = (t + q);
        }
    }
}

int main() {
    string txt = "ABCDABCD";
    string pat = "ABCD";
    RBSearch(pat, txt); // O((n-m) * m)
    return 0;
}
