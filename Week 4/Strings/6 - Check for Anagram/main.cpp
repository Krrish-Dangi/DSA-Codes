#include <algorithm>
#include <iostream>

using namespace std;

bool naive(string s1, string s2) {
     if (s1.length() != s2.length()) {
          return false;
     }
     sort(s1.begin(), s1.end());
     sort(s2.begin(), s2.end());
     return s1 == s2;
}

bool best(string s1, string s2) {
     if (s1.length() != s2.length()) {
          return false;
     }

     int count[26]{0};
     for (int i = 0; i < 26; i++) {
          count[s1[i] - 'a']++;
          count[s2[i] - 'a']--;
     }
     for (int i = 0; i < 26; i++) {
          if (count[i] != 0) {
               return false;
          }
     }
     return true;
}

int main() {
     string s1 = "abcaa";
     string s2 = "acbab";
     cout << boolalpha;
     cout << naive(s1, s2) << endl; // theta(nlogn)
     cout << best(s1, s2) << endl; // theta(n + char)
}