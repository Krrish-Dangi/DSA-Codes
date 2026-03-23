#include <iostream>
#include <vector>

using namespace std;

bool areDistinct(string str, int i, int j) {
    vector<bool> visited(256, false);
    for (int k = i; k <= j; k++) {
        if (visited[str[k]]) return false;
        visited[str[k]] = true;
    }
    return true;
}

int naive(string str) {
    int n = str.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (areDistinct(str, i, j)) {
                res = max(res, j - i + 1);
            }
        }
    }
    return res;
}

int better(string str) {
    int n = str.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        vector<bool> visited(256, false);
        for (int j = i; j < n; j++) {
            if (visited[str[j]]){
                break;
            }else {
                res = max(res, j - i + 1);
                visited[str[j]] = true;
            }
        }
    }
    return res;
}

int best(string s) {
    int n = s.size();
    int res = 0;
    vector<int> prev(256, -1);
    int i = 0;
    for (int j = 0; j < n; j++) {
        i = max(i,prev[s[j]] + 1);
        int maxEnd = j-i+1;
        res = max(res, maxEnd);
        prev[s[j]] = j;
    }
    return res;
}

int main() {
    string str{"abac"};
    cout << naive(str) << endl; // O(n**3)
    cout << better(str) << endl; // O(n**2)
    cout << naive(str) << endl; // O(n)
    return 0;
}
