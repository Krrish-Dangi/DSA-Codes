#include <iostream>
#include <stack>

using namespace std;

bool matching(char t, char c) {
    return (t=='(' && c==')' || t=='{' && c=='}' || t=='[' && c==']');
}

bool checkParanthesis(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }else{
            if (st.empty()) {
                return false;
            }
            if (matching(st.top(), c) ==  false) {
                return false;
            }else {
                st.pop();
            }
        }
    }
    return st.empty();
}

int main() {
    string s = "([])";
    cout << boolalpha;
    cout << checkParanthesis(s) << endl; // O(n) and O(n)
    return 0;
}