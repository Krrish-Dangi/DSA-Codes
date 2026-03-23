#include <iostream>

using namespace std;

int better(string s) {
    int count[26]{0};
    for (int i = 0; i < s.length(); i++) {
        count[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] > 1) {
            return i;
        }
    }
    return -1;
}

int best(string s) {
    int fIndex[256];
    fill(fIndex, fIndex + 256, -1);
    int res = INT_MAX;
    for (int i = 0; i < s.length(); i++) {
        int fi = fIndex[s[i]];
        if (fi == -1) {
            fIndex[s[i]] = i;
        }else {
            res = min(res,fi);
        }
    }
    return res == INT_MAX ? -1 : res;
}

int goat(string s) {
    bool visited[256];
    int res = -1;
    fill(visited, visited + 256, false);
    for (int i = s.length(); i > 0; i--) {
        if (visited[s[i]] == false) {
            visited[s[i]] = true;
        }else {
            res = i;
        }
    }
    return res;
}

int main() {
    string s{"abccbd"};
    cout << better(s) << endl;
    cout << best(s) << endl; // O(n)
    cout << goat(s) << endl; // O(n)
    return 0;
}